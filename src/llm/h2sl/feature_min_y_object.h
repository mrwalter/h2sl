/**
 * @file feature_min_y_object.h
 * 
 * @brief
 * 
 * Class used to describe a feature of the object number
 */

#ifndef H2SL_FEATURE_MIN_Y_OBJECT_H
#define H2SL_FEATURE_MIN_Y_OBJECT_H

#include <iostream>
#include <libxml/tree.h>

#include "h2sl/feature.h"

namespace h2sl {
  /**
   * Feature_Min_Y_Object class definition
   */
  class Feature_Min_Y_Object : public Feature {
  public:
    Feature_Min_Y_Object( const bool& invert = false );
    Feature_Min_Y_Object( const Feature_Min_Y_Object& other );
    virtual ~Feature_Min_Y_Object();
    Feature_Min_Y_Object& operator=( const Feature_Min_Y_Object& other );
 
    virtual bool value( const unsigned int& cv, const h2sl::Grounding* grounding, const std::vector< std::pair< const h2sl::Phrase*, std::vector< h2sl::Grounding* > > >& children, const h2sl::Phrase* phrase, const World* world );
    virtual bool value( const unsigned int& cv, const h2sl::Grounding* grounding, const std::vector< std::pair< const h2sl::Phrase*, std::vector< h2sl::Grounding* > > >& children, const h2sl::Phrase* phrase, const World* world, const Grounding* context );
    
    virtual void from_xml( const std::string& file );
    virtual void from_xml( xmlNodePtr root );
    virtual void to_xml( const std::string& file )const;
    virtual void to_xml( xmlDocPtr doc, xmlNodePtr root )const;

    virtual inline const h2sl::feature_type_t type( void )const{ return h2sl::FEATURE_TYPE_GROUNDING; };

  protected:

  private:

  };

  /** 
   * Feature_Min_Y_Object class ostream operator
   */
  std::ostream& operator<<( std::ostream& out, const Feature_Min_Y_Object& other );
}

#endif /* H2SL_FEATURE_MIN_Y_OBJECT_H */
