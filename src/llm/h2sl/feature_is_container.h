/**
 * @file feature_is_container.h
 *
 * @brief
 *
 * Class used to describe a feature object matches child..
 */

#ifndef H2SL_FEATURE_IS_CONTAINER_H
#define H2SL_FEATURE_IS_CONTAINER_H

#include <iostream>
#include <libxml/tree.h>

#include "h2sl/feature.h"

namespace h2sl {
    /**
     * Feature_Is_Container
     */
    class Feature_Is_Container: public Feature {
    public:
        Feature_Is_Container( const bool& invert = false );
        virtual ~Feature_Is_Container();
        Feature_Is_Container( const Feature_Is_Container& other );
        Feature_Is_Container& operator=( const Feature_Is_Container& other );
        
        virtual bool value( const unsigned int& cv, const h2sl::Grounding* grounding, const std::vector< std::pair< const h2sl::Phrase*, std::vector< h2sl::Grounding* > > >& children, const h2sl::Phrase* phrase, const World* world );
        
        virtual void to_xml( xmlDocPtr doc, xmlNodePtr root )const;
        
        virtual void from_xml( xmlNodePtr root );
        
        virtual inline const h2sl::feature_type_t type( void )const{ return h2sl::FEATURE_TYPE_GROUNDING; };
        
    protected:
        
    private:
        
    };
    
    /**
     * Feature_Is_Container class ostream operator
     */
    
    std::ostream& operator<<( std::ostream& out, const Feature_Is_Container& other );
}

#endif /* H2SL_FEATURE_IS_CONTAINER_H */



