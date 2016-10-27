/**
 * @file region.h
 *
 * @brief
 *
 * a class that describes a region in relation to an container
 */

#ifndef H2SL_REGION_CONTAINER_H
#define H2SL_REGION_CONTAINER_H

#include <iostream>
#include <libxml/tree.h>

#include "h2sl/grounding.h"
#include "h2sl/container.h"
#include "h2sl/spatial_relation.h"

namespace h2sl {
  /**
   * Region_Container class definition
   */
  class Region_Container : public Grounding {
  public:
    Region_Container( const std::string& spatial_relationType = "na",
                      const Container& container = Container() );
    virtual ~Region_Container();
    Region_Container( const Region_Container& other );
    Region_Container( xmlNodePtr root );
    Region_Container& operator=( const Region_Container& other );
    bool operator==( const Region_Container& other )const;
    bool operator!=( const Region_Container& other )const;
    virtual Region_Container* dup( void )const;
    
    virtual void from_xml( const std::string& file );
    virtual void from_xml( xmlNodePtr root );
    virtual void to_xml( const std::string& file )const;
    virtual void to_xml( xmlDocPtr doc, xmlNodePtr root )const;

    inline std::string& relation_type( void ){ return get_prop< std::string >( _properties, "spatial_relation_type" ); };
    inline const std::string& relation_type( void )const{ return get_prop< std::string >( _properties, "spatial_relation_type" ); };
    
    inline Container& container( void ){ return _container; };
    inline const Container& container( void )const{ return _container; };
   
  protected:
      Container _container;
  
  private:

  };

  /**
   * Region_Container class ostream operator
   */ 
  std::ostream& operator<<( std::ostream& out, const Region_Container& other );
}

#endif /* H2SL_REGION_CONTAINER_H */
