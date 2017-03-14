/**
 * @file rule_constraint_reference_type.h
 * 
 * @brief
 * 
 * a class used to describe a rule for a spatial relationship
 */

#ifndef H2SL_RULE_CONSTRAINT_REFERENCE_TYPE_H
#define H2SL_RULE_CONSTRAINT_REFERENCE_TYPE_H

#include <iostream>
#include <libxml/tree.h>

#include "h2sl/symbol_dictionary.h"
#include "h2sl/world.h"
#include "h2sl/rule.h"

namespace h2sl {
  /**
   * Rule_Constraint_Reference_Type class definition
   */
  class Rule_Constraint_Reference_Type : public Rule {
  public:

    Rule_Constraint_Reference_Type( const std::string& constraintReferenceType = "na" );
    Rule_Constraint_Reference_Type( const Rule_Constraint_Reference_Type& other );
    Rule_Constraint_Reference_Type( xmlNodePtr root );
    virtual ~Rule_Constraint_Reference_Type();
    Rule_Constraint_Reference_Type& operator=( const Rule_Constraint_Reference_Type& other );
    bool operator==( const Rule_Constraint_Reference_Type& other )const;
    bool operator!=( const Rule_Constraint_Reference_Type& other )const;
    virtual Rule_Constraint_Reference_Type* dup( void )const;

    virtual bool matches_class_name( const std::string& arg )const{ return ( arg == "rule_constraint_reference_type" ); };
    virtual void scrape_grounding( const World * world, std::map< std::string, std::vector< std::string > >& stringTypes, std::map< std::string, std::vector< int > >& intTypes )const;
    virtual void scrape_grounding( const World * world, std::vector< std::string >& classNames, std::map< std::string, std::vector< std::string > >& stringTypes, std::map< std::string, std::vector< int > >& intTypes )const;
    static void fill_search_space( const Symbol_Dictionary& symbolDictionary, const World* world, std::map< std::string, std::pair< std::string, std::vector< Grounding* > > >& searchSpaces, const symbol_type_t& symbolType );
 
    virtual void from_xml( const std::string& file );
    virtual void from_xml( xmlNodePtr root );
    virtual void to_xml( const std::string& file )const;
    virtual void to_xml( xmlDocPtr doc, xmlNodePtr root )const;

    inline std::string& constraint_reference_type( void ){ return get_prop< std::string >( _string_properties, "constraint_reference_type" ); };
    inline const std::string& constraint_reference_type( void )const{ return get_prop< std::string >( _string_properties, "constraint_reference_type" ); };

    static std::string class_name( void ){ return "rule_constraint_reference_type"; };

  protected:

  private:

  };

  /** 
   * Rule_Constraint_Reference_Type class ostream operator
   */
  std::ostream& operator<<( std::ostream& out, const Rule_Constraint_Reference_Type& other );
}

#endif /* H2SL_RULE_CONSTRAINT_REFERENCE_TYPE_H */
