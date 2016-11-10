/**
 * @file feature_container_dominant_y_shape.h
 * 
 * @brief
 * 
 * Class used to describe the feature container_dominant_y_shape
 */

#ifndef H2SL_FEATURE_CONTAINER_DOMINANT_Y_SHAPE_H
#define H2SL_FEATURE_CONTAINER_DOMINANT_Y_SHAPE_H

#include <iostream>
#include <libxml/tree.h>

#include "h2sl/feature.h"
#include "h2sl/object.h"

namespace h2sl {
  /**
   * Feature_Container_Dominant_Y_Shape class definition
   */
  class Feature_Container_Dominant_Y_Shape : public Feature {
  public:
    Feature_Container_Dominant_Y_Shape( const bool& invert = false, 
                                        const double& model_deviation_tolerance = 0.1, 
                                        const double& adjacent_distance_tolerance = 0.1, 
                                        const unsigned int& min_num_elements = 2 );
    Feature_Container_Dominant_Y_Shape( const Feature_Container_Dominant_Y_Shape& other );
    virtual ~Feature_Container_Dominant_Y_Shape();
    Feature_Container_Dominant_Y_Shape& operator=( const Feature_Container_Dominant_Y_Shape& other );

    virtual bool value( const unsigned int& cv, 
                        const Grounding* grounding, 
                        const std::vector< std::pair< const Phrase*, std::vector< Grounding* > > >& children, 
                        const Phrase* phrase, 
                        const World* world );

    virtual bool value( const unsigned int& cv, 
                        const Grounding* grounding, 
                        const std::vector< std::pair< const Phrase*,std::vector< Grounding* > > >& children, 
                        const Phrase* phrase, 
                        const World* world,
                        const Grounding* context );

    virtual void from_xml( const std::string& file );
    virtual void from_xml( xmlNodePtr root );
    virtual void to_xml( const std::string& file )const;
    virtual void to_xml( xmlDocPtr doc, xmlNodePtr root )const;

    inline double& model_deviation_tolerance(void) {return _model_deviation_tolerance;};
    inline const double& model_deviation_tolerance(void) const {return _model_deviation_tolerance;};

    inline double& adjacent_distance_tolerance(void) {return _adjacent_distance_tolerance;};
    inline const double& adjacent_distance_tolerance(void) const {return _adjacent_distance_tolerance;};

    inline unsigned int& min_num_elements (void) {return _min_num_elements;};
    inline const unsigned int& min_num_elements (void)const {return _min_num_elements;};

    // Main structure finding function.
    static bool container_expresses_dominant_y_structure( const std::vector < Object* >& container, 
                                                          const double& model_deviation_tolerance = 0.1, 
                                                          const double& adjacent_distance_tolerance = 0.1, 
                                                          const unsigned int& min_num_elements = 2 );
 
    virtual inline const h2sl::feature_type_t type( void )const{ return h2sl::FEATURE_TYPE_GROUNDING; };

 protected:
    double _model_deviation_tolerance;
    double _adjacent_distance_tolerance;
    unsigned int _min_num_elements;

  private:

  };

  /** 
   * Feature_Container_Dominant_Y_Shape class ostream operator
   */
  std::ostream& operator<<( std::ostream& out, const Feature_Container_Dominant_Y_Shape& other );
}

#endif /* H2SL_FEATURE_CONTAINER_DOMINANT_Y_SHAPE_H */

