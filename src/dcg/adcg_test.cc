/**
 * @file    adcg_test.cc
 * @author  Thomas M. Howard (tmhoward@csail.mit.edu)
 *          Matthew R. Walter (mwalter@csail.mit.edu)
 * @version 1.0
 *
 * @section LICENSE
 *
 * This file is part of h2sl.
 *
 * Copyright (C) 2014 by the Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see
 * <http://www.gnu.org/licenses/gpl-2.0.html> or write to the Free
 * Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 * @section DESCRIPTION
 *
 * A ADCG class test program
 */

#include <iostream>
#include <cassert>
#include <sys/time.h>
#include "h2sl/common.h"
#include "h2sl/phrase.h"
#include "h2sl/constraint.h"
#include "h2sl/grounding_set.h"
#include "h2sl/parser_cyk.h"
#include "h2sl/adcg.h"
#include "adcg_test_cmdline.h"

using namespace std;
using namespace h2sl;

/**
 * Clear the phrase. 
 */
void
clear( Phrase* phrase ){
  if( phrase != NULL ){
    if( phrase->grounding_set() != NULL ){
      delete_ptr< Grounding_Set >( phrase->grounding_set() );
    }
    for( unsigned int i = 0; i < phrase->children().size(); i++ ){
      clear( phrase->children()[ i ] );
    }
  }
  return;
}

/**
 * Complete: Compare Phrases 
 */
bool
compare_phrases( const Phrase& a,
                const Phrase& b ){
  assert( dynamic_cast< const Grounding_Set* >( a.grounding_set() ) != NULL );
  assert( dynamic_cast< const Grounding_Set* >( b.grounding_set() ) != NULL );

  bool value = true;
  value = value && ( a.children().size() == b.children().size() );
  if( a.children().size() == b.children().size() ){
    for( unsigned int i = 0; i < a.children().size(); i++ ){
      value = value && compare_phrases( *a.children()[ i ], *b.children()[ i ] );
    }
  }

  value = value && ( *( static_cast< const Grounding_Set* >( a.grounding_set() ) ) == *( static_cast< const Grounding_Set* >( b.grounding_set() ) ) );

  return value;
}

int
main( int argc,
      char* argv[] ) {
  int status = 0;
  cout << "start of ADCG class test program" << endl;

  gengetopt_args_info args;
  if( cmdline_parser( argc, argv, &args ) != 0 ){
    exit(1);
  }

  Parser< Phrase > * parser = new Parser_CYK< Phrase >();
  Grammar * grammar = new Grammar();
  if( args.grammar_given ){
    grammar->from_xml( args.grammar_arg );
  }

  Feature_Set * feature_set = new Feature_Set();
  LLM * llm = new LLM( feature_set );
  if( args.llm_given ){
    llm->from_xml( args.llm_arg );
  }

  Symbol_Dictionary * symbol_dictionary = new Symbol_Dictionary( args.symbol_dictionary_groundings_arg );

  Search_Space * search_space = new Search_Space();

  ADCG * adcg = new ADCG();

  unsigned int num_correct = 0;
  unsigned int num_incorrect = 0;

  for( unsigned int i = 0; i < args.inputs_num; i++ ){
    cout << "reading file " << args.inputs[ i ] << endl;
    string instruction = extract_instruction( args.inputs[ i ] );
    cout << "  found instruction \"" << instruction << "\"" << endl;

    Grounding * context = NULL;

    World * world = new World();  
    world->from_xml( args.inputs[ i ] );

    Phrase * truth = new Phrase();
    truth->from_xml( args.inputs[ i ] );

    // update the search space when the world changes
    search_space->fill_groundings( *symbol_dictionary, world );
    cout << "search_space:" << *search_space << endl;

    vector< Phrase* > phrases;
    //phrases.push_back( truth );

    
    //conditional flow to allow use of parser or not
    if( !args.grammar_given ){    
      cout << "grammar not provided, scraping example..." << endl;
      //add a copy of 'truth' to the phrases vector
      phrases.push_back( new Phrase() );
      phrases.back() = truth->dup();
      //remove the annotations from the copy
      clear( phrases.back() );
      //inference on scraped phrase
      adcg->leaf_search( phrases.back(), *symbol_dictionary, search_space, world, context, llm, args.beam_width_arg, ( bool )( args.debug_arg ) );
      if( !adcg->solutions().empty() ){ 
        cout << "num_phrases: " << to_std_string( adcg->solutions().front().second->num_phrases() ) << endl;

        cout << "solution: " << *adcg->solutions().front().second << " (" << adcg->solutions().front().first << ")" << endl;

        cout << "search space( concrete_size ) : " << to_std_string( adcg->solutions().front().second->aggregate_property_phrases( std::string( "concrete_size" ) ) ) << endl;
        cout << "search space( abstract_max_size ) : " << to_std_string( adcg->solutions().front().second->aggregate_property_phrases( std::string( "abstract_max_size" ) ) ) << endl;
        cout << "search space( abstract_avg_size ) : " << to_std_string( adcg->solutions().front().second->aggregate_property_phrases( std::string( "abstract_avg_size" ) ) ) << endl;
        cout << "search space( avg_abstract_avg_size ) : " << to_std_string( adcg->solutions().front().second->statistic_aggregate_property_phrases( "abstract_avg_size", "per-phrase-avg" ) ) << endl;
        cout << "search space( avg_abstract_max_size ) : " << to_std_string( adcg->solutions().front().second->statistic_aggregate_property_phrases( "abstract_max_size", "per-phrase-avg" ) ) << endl;
        cout << "search space( avg_concrete_size ) : " << to_std_string( adcg->solutions().front().second->statistic_aggregate_property_phrases( "concrete_size", "per-phrase-avg" ) ) << endl;

        //compare the solution to the 'truth'
        if( compare_phrases( *truth, *adcg->solutions().front().second ) ) {
          cout << "solution matches" << endl;
          num_correct++;
        } else{
          cout << "solution does not match" << endl;
          num_incorrect++;
        }
      }
    } else{
      cout << "grammar provided, parsing..." << endl;
      //fill the 'phrases' vector with the results of the parsing
      if( parser->parse( *grammar, instruction, phrases ) ){
        if( !phrases.empty() ){
          cout << "found " << phrases.size() << " phrases" << endl;
          cout << "  truth:" << *truth << endl;
          bool found_match = false;
          unsigned int match_index = 0;
          for( unsigned int i = 0; i < phrases.size(); i++ ){
            if( phrases[ i ] != NULL ){
              adcg->leaf_search( phrases[ i ], *symbol_dictionary, search_space, world, context, llm, args.beam_width_arg, ( bool )( args.debug_arg ) );
              if( !adcg->solutions().empty() ){
                cout << "  parse[" << i << "]:" << *adcg->solutions().front().second << " (" << adcg->solutions().front().first << ")" << endl;
                if( compare_phrases( *truth, *adcg->solutions().front().second ) ){
                  found_match = true;
                  match_index = i;
                }
              }
            }
          }
          if( found_match ){
            cout << "  phrase[" << match_index << "] matches" << endl;
            num_correct++;
          } else {
            cout << "  did not find match" << endl;
            num_incorrect++;
            exit(0);
          }
        }
      } else {
        cout << "  could not parse \"" << instruction << "\"" << endl;
        num_incorrect++;
        exit(0);
      }
    }

    cout << "printing phrases" << endl;
    for( unsigned int i = 0; i < phrases.size(); i++ ){
        cout << "  " << *phrases[ i ] << endl;
    }

    // write the solution to xml
    // get the example number from the filename
    string filename = args.inputs[ i ];
    string example_number_string = filename.substr( ( filename.size() - 8 ), 4 );
    stringstream output_filename;
    if( args.output_given ){
      output_filename << args.output_arg << "/adcg_solution_" << example_number_string << ".xml";
      adcg->solutions().front().second->to_xml( output_filename.str() );
    } else{
      output_filename << "/tmp/adcg_solution_" << example_number_string << ".xml";
      adcg->solutions().front().second->to_xml( output_filename.str() );
    }


    for( unsigned int i = 0; i < phrases.size(); i++ ){
      if( phrases[ i ] != NULL ){
        delete phrases[ i ];
        phrases[ i ] = NULL;
      }
    }

    if( truth != NULL ){
      delete truth;
      truth = NULL;
    }

    if( world != NULL ){
      delete world;
      world = NULL;
    } 
  }

  cout << "correctly inferred " << num_correct << " of " << num_correct + num_incorrect << " examples (" << ( double )( num_correct ) / ( double )( num_correct + num_incorrect ) * 100.0 << "%)" << endl;

  if( adcg != NULL ){
    delete adcg;
    adcg = NULL;
  }

  if( llm != NULL ){
    delete llm;
    llm = NULL;
  }

  if( feature_set != NULL ){
    delete feature_set;
    feature_set = NULL;
  }

  if( grammar != NULL ){
    delete grammar;
    grammar = NULL;
  }

  if( parser != NULL ){
    delete parser;
    parser = NULL;
  }

  cout << "end of ADCG class test program" << endl;
  return status;
}
