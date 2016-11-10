/**
 * @file feature_container_matches_child.h
 *
 * @brief
 *
 * Class used to describe a feature container matches child..
 */

#ifndef H2SL_FEATURE_CONTAINER_MATCHES_CHILD_H
#define H2SL_FEATURE_CONTAINER_MATCHES_CHILD_H

#include <iostream>
#include <libxml/tree.h>

#include "h2sl/feature.h"

namespace h2sl {
    /**
     * Feature_Container_Matches_Child
     */
    class Feature_Container_Matches_Child: public Feature {
    public:
        Feature_Container_Matches_Child( const bool& invert = false );
        virtual ~Feature_Container_Matches_Child();
        Feature_Container_Matches_Child( const Feature_Container_Matches_Child& other );
        Feature_Container_Matches_Child& operator=( const Feature_Container_Matches_Child& other );
        
        virtual bool value( const unsigned int& cv, const Grounding* grounding, const std::vector< std::pair< const Phrase*, std::vector< Grounding* > > >& children, const Phrase* phrase, const World* world );
        virtual bool value( const unsigned int& cv, const Grounding* grounding, const std::vector< std::pair< const Phrase*, std::vector< Grounding* > > >& children, const Phrase* phrase, const World* world, const Grounding* context );
        
        virtual void to_xml( xmlDocPtr doc, xmlNodePtr root )const;
        
        virtual void from_xml( xmlNodePtr root );
        
        virtual inline const h2sl::feature_type_t type( void )const{ return h2sl::FEATURE_TYPE_GROUNDING; };
        
    protected:
        
    private:
        
    };
    
    /**
     * Feature_Container_Matches_Child class ostream operator
     */
    
    std::ostream& operator<<( std::ostream& out, const Feature_Container_Matches_Child& other );
}

#endif /* H2SL_FEATURE_CONTAINER_MATCHES_CHILD_H */



