/**
 * @file feature_region_container_merge_container_spatial_relation.h
 *
 * @brief
 *
 * Class used to describe a feature container matches child..
 */

#ifndef H2SL_FEATURE_REGION_CONTAINER_MERGE_CONTAINER_SPATIAL_RELATION_H
#define H2SL_FEATURE_REGION_CONTAINER_MERGE_CONTAINER_SPATIAL_RELATION_H

#include <iostream>
#include <libxml/tree.h>

#include "h2sl/feature.h"

namespace h2sl {
    /**
     * Feature_Region_Container_Merge_Container_Spatial_Relation
     */
    class Feature_Region_Container_Merge_Container_Spatial_Relation: public Feature {
    public:
        Feature_Region_Container_Merge_Container_Spatial_Relation( const bool& invert = false, const bool& conceptOrder = false );
        virtual ~Feature_Region_Container_Merge_Container_Spatial_Relation();
        Feature_Region_Container_Merge_Container_Spatial_Relation( const Feature_Region_Container_Merge_Container_Spatial_Relation& other );
        Feature_Region_Container_Merge_Container_Spatial_Relation& operator=( const Feature_Region_Container_Merge_Container_Spatial_Relation& other );
        
        virtual bool value( const unsigned int& cv, const h2sl::Grounding* grounding, const std::vector< std::pair< const h2sl::Phrase*, std::vector< h2sl::Grounding* > > >& children, const h2sl::Phrase* phrase, const World* world );
        
        virtual void to_xml( xmlDocPtr doc, xmlNodePtr root )const;
        
        virtual void from_xml( xmlNodePtr root );
        
        inline bool& concept_order( void ){ return _concept_order; };
        inline const bool& concept_order( void )const{ return _concept_order; };

        virtual inline const h2sl::feature_type_t type( void )const{ return h2sl::FEATURE_TYPE_GROUNDING; };
        
    protected:
        bool _concept_order;       
 
    private:
        
    };
    
    /**
     * Feature_Region_Container_Merge_Container_Spatial_Relation class ostream operator
     */
    
    std::ostream& operator<<( std::ostream& out, const Feature_Region_Container_Merge_Container_Spatial_Relation& other );
}

#endif /* H2SL_FEATURE_REGION_CONTAINER_MERGE_CONTAINER_SPATIAL_RELATION_H */



