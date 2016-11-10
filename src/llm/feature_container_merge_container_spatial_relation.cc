/**
 * @file feature_container_merge_container_spatial_relation.cc
 *
 * @brief
 *
 * Class used to describe a feature container matches child type
 */

#include <assert.h>
#include <sstream>

#include "h2sl/feature_container_merge_container_spatial_relation.h"
#include "h2sl/container.h"
#include "h2sl/spatial_relation.h"

using namespace std;
using namespace h2sl;

/**
 * Feature_Container_Merge_Container_Spatial_Relation class constructor
 */
Feature_Container_Merge_Container_Spatial_Relation::
Feature_Container_Merge_Container_Spatial_Relation( const bool& invert ) : Feature( invert ) {
    
}

/**
 * Feature_Container_Merge_Container_Spatial_Relation class destructor
 */
Feature_Container_Merge_Container_Spatial_Relation::
~Feature_Container_Merge_Container_Spatial_Relation() {
    
}

/**
 * Feature_Container_Merge_Container_Spatial_Relation class copy constructor
 */
Feature_Container_Merge_Container_Spatial_Relation::
Feature_Container_Merge_Container_Spatial_Relation( const Feature_Container_Merge_Container_Spatial_Relation& other ) : Feature( other ) {
    
}

/**
 * Feature_Container_Merge_Container_Spatial_Relation class assignment operator
 */
Feature_Container_Merge_Container_Spatial_Relation&
Feature_Container_Merge_Container_Spatial_Relation::
operator=( const Feature_Container_Merge_Container_Spatial_Relation& other ) {
    _invert = other._invert;
    return (*this);
}

/**
 * returns the value of the feature.
 */
bool
Feature_Container_Merge_Container_Spatial_Relation::
value( const unsigned int& cv,
        const Grounding* grounding,
        const vector< pair< const Phrase*, vector< Grounding* > > >& children,
        const Phrase* phrase,
        const World* world ){
  return value( cv, grounding, children, phrase, world, NULL );
}

bool
Feature_Container_Merge_Container_Spatial_Relation::
value( const unsigned int& cv,
        const Grounding* grounding,
        const vector< pair< const Phrase*, vector< Grounding* > > >& children,
        const Phrase* phrase,
        const World* world,
        const Grounding* context ){
    const Container * container = dynamic_cast< const Container* >( grounding );
    if( ( container != NULL ) && ( !children.empty() ) ){
      pair< const h2sl::Phrase*, const Container* > container_child( NULL, NULL );
      pair< const h2sl::Phrase*, const Spatial_Relation* > spatial_relation_child( NULL, NULL );
      for( unsigned int i = 0; i < children.size(); i++ ){
        for( unsigned int j = 0; j < children[ i ].second.size(); j++ ){
          if( dynamic_cast< const Container* >( children[ i ].second[ j ] ) != NULL ){
            container_child.first = children[ i ].first;
            container_child.second = static_cast< const Container* >( children[ i ].second[ j ] );
          } else if ( dynamic_cast< const Spatial_Relation* >( children[ i ].second[ j ] ) != NULL ){
            spatial_relation_child.first = children[ i ].first;
            spatial_relation_child.second = static_cast< const Spatial_Relation* >( children[ i ].second[ j ] );
          }
        }
      }

      if( ( container_child.first != NULL ) && ( container_child.second != NULL ) && ( spatial_relation_child.first != NULL ) && ( spatial_relation_child.second != NULL ) ){ 
        if( container_child.first->min_word_order() < spatial_relation_child.first->min_word_order() ){
          if( *container == *container_child.second ){
            return !_invert;
          }
        }
        return _invert;
      }
    }
    return false;
}

/**
 * exports the Feature_Container_Merge_Container_Spatial_Relation class to an XML file
 */
void
Feature_Container_Merge_Container_Spatial_Relation::
to_xml( xmlDocPtr doc, xmlNodePtr root )const{
    xmlNodePtr node = xmlNewDocNode( doc, NULL, ( xmlChar* )( "feature_container_merge_container_spatial_relation" ), NULL );
    stringstream invert_string;
    invert_string << _invert;
    xmlNewProp( node, ( const xmlChar* )( "invert" ), ( const xmlChar* )( invert_string.str().c_str() ) );
    xmlAddChild( root, node );
    return;
}

/**
 * imports the Feature_Container_Merge_Container_Spatial_Relation class from an XML file
 */
void
Feature_Container_Merge_Container_Spatial_Relation::
from_xml( xmlNodePtr root ){
    _invert = false;
    if( root->type == XML_ELEMENT_NODE ){
        xmlChar * tmp = xmlGetProp( root, ( const xmlChar* )( "invert" ) );
        if( tmp != NULL ){
            string invert_string = ( char* )( tmp );
            _invert = ( bool )( strtol( invert_string.c_str(), NULL, 10 ) );
            xmlFree( tmp );
        }
    }
    return;
}

namespace h2sl {
    /**
     * Feature_Container_Merge_Container_Spatial_Relation class ostream operator
     */
    ostream&
    operator<<( ostream& out,
               const Feature_Container_Merge_Container_Spatial_Relation& other ) {
      out << "class:\"Feature_Container_Merge_Container_Spatial_Relation\" ";  
      return out;
    }
    
}
