/**
 * @file    abstract_container_demo.cc
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
 * An Abstract_Container class demo program
 */

#include <iostream>
#include <cstdlib>
#include "h2sl/abstract_container.h"
#include "abstract_container_demo_cmdline.h"

using namespace std;
using namespace h2sl;

void
fill_abstract_containers( vector< Abstract_Container* >& abstract_containers, const string filename ){
  xmlDoc * doc = NULL;
  xmlNode * root = NULL;
  doc = xmlReadFile( filename.c_str(), NULL, 0 );
  if( doc != NULL ){
    root = xmlDocGetRootElement( doc );
    if( root->type == XML_ELEMENT_NODE ){
      for( xmlNodePtr l1 = root->children; l1; l1 = l1->next ){
        if( l1->type == XML_ELEMENT_NODE ){
          if( xmlStrcmp( l1->name, ( const xmlChar* )( "abstract_container" ) ) == 0 ){
            abstract_containers.push_back( new Abstract_Container( l1 ) );
          }
        }
      }
    }
  }
  return;
}

int
main( int argc,
      char* argv[] ) {
  cout << "start of Abstract_Container class demo program" << endl;

  gengetopt_args_info args;
  if( cmdline_parser( argc, argv, &args ) != 0 ){
    exit(1);
  }

  vector< Abstract_Container* > abstract_containers;

  if( args.input_given ){
    fill_abstract_containers( abstract_containers, args.input_arg );
  }

  if( !abstract_containers.empty() ){
    cout << "Abstract_Container::class_name(): " << Abstract_Container::class_name() << endl;
    cout << "abstract_containers.back()->class_name(): " << abstract_containers.back()->class_name() << endl;
    for( unsigned int i = 0; i < abstract_containers.size(); i++ ){
      cout << "abstract_containers[ " << i << " ]: " << *abstract_containers[ i ] << endl;
    }
  } else{
    cout << "the input did not have examples of abstract_container, so we just demo the static functions and ostream operator for the default" << endl;
    abstract_containers.push_back( new Abstract_Container() );
    cout << "abstract_container:( " << *abstract_containers.back() << endl;
    cout << "abstract_container->class_name(): " << abstract_containers.back()->class_name() << endl;
    cout << "Abstract_Container::class_name(): " << Abstract_Container::class_name() << endl;
  }

  if( args.output_given ){
    xmlDocPtr doc = xmlNewDoc( ( xmlChar* )( "1.0" ) );
    xmlNodePtr root = xmlNewDocNode( doc, NULL, ( xmlChar* )( "root" ), NULL );
    xmlDocSetRootElement( doc, root );
    for( unsigned int i = 0; i < abstract_containers.size(); i++ ){
      abstract_containers[ i ]->to_xml( doc, root );
    }
    xmlSaveFormatFileEnc( args.output_arg, doc, "UTF-8", 1 );
    xmlFreeDoc( doc );
  }

  //memory management
  for( unsigned int i = 0; i < abstract_containers.size(); i++ ){
    if( abstract_containers[ i ] != NULL ){
      delete abstract_containers[ i ];
      abstract_containers[ i ] = NULL;
    }
  }

  cout << "end of Abstract_Container class demo program" << endl;
  return 0;
}
