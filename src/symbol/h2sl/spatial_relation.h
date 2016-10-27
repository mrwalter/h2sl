/**
 * @file spatial_relation.h
 * 
 * @brief
 * 
 * a class used to describe a spatial relationship
 */

#ifndef H2SL_SPATIAL_RELATION_H
#define H2SL_SPATIAL_RELATION_H

#include <iostream>
#include <libxml/tree.h>

#include "h2sl/grounding.h"
#include "h2sl/object.h"

namespace h2sl {
  /**
   * Spatial_Relation class definition
   */
  class Spatial_Relation : public Grounding {
  public:

    Spatial_Relation( const std::string& spatial_relationType = "na" );
    Spatial_Relation( const Spatial_Relation& other );
    Spatial_Relation( xmlNodePtr root );
    virtual ~Spatial_Relation();
    Spatial_Relation& operator=( const Spatial_Relation& other );
    bool operator==( const Spatial_Relation& other )const;
    bool operator!=( const Spatial_Relation& other )const;
    virtual Spatial_Relation* dup( void )const;
 
    virtual void from_xml( const std::string& file );
    virtual void from_xml( xmlNodePtr root );
    virtual void to_xml( const std::string& file )const;
    virtual void to_xml( xmlDocPtr doc, xmlNodePtr root )const;

    inline std::string& relation_type( void ){ return get_prop< std::string >( _properties, "spatial_relation_type" ); };
    inline const std::string& relation_type( void )const{ return get_prop< std::string >( _properties, "spatial_relation_type" ); };

  protected:

  private:

  };

  /** 
   * Spatial_Relation class ostream operator
   */
  std::ostream& operator<<( std::ostream& out, const Spatial_Relation& other );
}

#endif /* H2SL_SPATIAL_RELATION_H */
