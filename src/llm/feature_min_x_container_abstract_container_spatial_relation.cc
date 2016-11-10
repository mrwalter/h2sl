/**
 * @file feature_min_x_container_abstract_container_spatial_relation.cc
 *
 * @brief
 *
 * Class used to describe a feature of the feature min x container abstract container spatial relation.
 */
#include <assert.h>
#include <sstream>
#include <algorithm>

#include "h2sl/feature_min_x_container_abstract_container_spatial_relation.h"
#include "h2sl/spatial_relation.h"
#include "h2sl/container.h"
#include "h2sl/abstract_container.h"

using namespace std;
using namespace h2sl;

/* 
 * Sorting according to min_x
 * Used in the value function.
 */

//bool
//min_x_sort_container_abstract_container( Object* a,
//        Object* b ){
//  return a->transform().position().x() < b->transform().position().x();
//}

bool
min_x_sort_container_abstract_container (Grounding* a, Grounding* b) {
  if ((dynamic_cast< const Object* >(a) != NULL) && (dynamic_cast< const Object* >(b) != NULL)) {
  return ( ((dynamic_cast< const Object* >(a))->transform().position().x()) <
          ((dynamic_cast< const Object* >(b))->transform().position().x()) );
  } else {
  cout << "Cannot cast container entity into Object" << endl;
  return false;
  }
}

/**
 * Feature_Min_X_Container_Abstract_Container_Spatial_Relation class constructor
 */
Feature_Min_X_Container_Abstract_Container_Spatial_Relation::
Feature_Min_X_Container_Abstract_Container_Spatial_Relation( const bool& invert,
                          const std::string& relationType ) : Feature( invert ),
                                                              _relation_type( relationType ) {

}

/**
 * Feature_Min_X_Container_Abstract_Container_Spatial_Relation class copy constructor
 */
Feature_Min_X_Container_Abstract_Container_Spatial_Relation::
Feature_Min_X_Container_Abstract_Container_Spatial_Relation( 
                               const Feature_Min_X_Container_Abstract_Container_Spatial_Relation& other ) : 
                               Feature( other ),
                               _relation_type( other._relation_type ) {

}

/**
 * Feature_Min_X_Container_Abstract_Container_Spatial_Relation class destructor
 */
Feature_Min_X_Container_Abstract_Container_Spatial_Relation::
~Feature_Min_X_Container_Abstract_Container_Spatial_Relation() {

}

/** 
 * Feature_Min_X_Container_Abstract_Container_Spatial_Relation class assignment operator
 */
Feature_Min_X_Container_Abstract_Container_Spatial_Relation&
Feature_Min_X_Container_Abstract_Container_Spatial_Relation::
operator=( const Feature_Min_X_Container_Abstract_Container_Spatial_Relation& other ){
  _invert = other._invert;
  _relation_type = other._relation_type;
  return (*this);
}

/**
 * returns the value of the feature
 */
bool
Feature_Min_X_Container_Abstract_Container_Spatial_Relation::
value( const unsigned int& cv,
        const h2sl::Grounding* grounding,
        const vector< pair< const h2sl::Phrase*, vector< h2sl::Grounding* > > >& children,
        const h2sl::Phrase* phrase,
        const World* world) { 
        return value( cv, grounding, children, phrase, world, NULL );

}
 
/**
 * returns the value of the feature with context.
 */
bool
Feature_Min_X_Container_Abstract_Container_Spatial_Relation::
value( const unsigned int& cv,
        const h2sl::Grounding* grounding,
        const vector< pair< const h2sl::Phrase*, vector< h2sl::Grounding* > > >& children,
        const h2sl::Phrase* phrase,
        const World* world, 
        const Grounding* context ){
  // The grounding under consideration is the container.
  // Find abstract container and spatial relation in the children.
  const Container* container = dynamic_cast< const Container* >( grounding );
  Abstract_Container* abstract_container_child = NULL;
  Spatial_Relation* spatial_relation_child = NULL;
  for( unsigned int i = 0; i < children.size(); i++ ){
    for( unsigned int j = 0; j < children[ i ].second.size(); j++ ){
      if( dynamic_cast< Abstract_Container* >( children[ i ].second[ j ] ) != NULL ){
        abstract_container_child = static_cast< Abstract_Container* >( children[ i ].second[ j ] );
      } else if ( dynamic_cast< Spatial_Relation* >( children[ i ].second[ j ] ) != NULL ){
        spatial_relation_child = static_cast< Spatial_Relation* >( children[ i ].second[ j ] );
      }
    }
  }

  // Check all the conditions where the feature does not apply.a
  // Return false.
  if ((abstract_container_child == NULL) || (spatial_relation_child == NULL) 
     || (container == NULL) || ( dynamic_cast< const Object* >(container->container().front()) == NULL )
     || (spatial_relation_child->relation_type() != _relation_type)) {
      return false;
  }

  // Create vector.
  // Fill in objects from the world that match AC object type. 
  vector< Object* > type_matched_obj;
  for( unsigned int i = 0; i < world->objects().size(); i++ ) {
    if( world->objects()[ i ]->type() == abstract_container_child->type() ) {
      type_matched_obj.push_back( world->objects()[ i ] );
    }
  }
  
  // Sort according to the x-coordinate.
  // Different types of sort functions imply different predictors. 
  sort( type_matched_obj.begin(), type_matched_obj.end(), 
                  min_x_sort_container_abstract_container );

  // Check upto the number of elements implied by the AC in the object match array. 
  // if they match with any of the objects in the container grounding. 
  // This is in the context of a spatial relation.
  unsigned int ac_number_value = world->numeric_map()[ abstract_container_child->number() ]; 
  if (container->container().size() == ac_number_value) {
    bool allObjectsFound = true;
    bool isEqual = false;
    for (unsigned int i = 0; i < ac_number_value; ++i) {
      isEqual = false;
      for (unsigned int j = 0; j < container->container().size(); j++) {
        if (*type_matched_obj[ i ] == *dynamic_cast< const Object* >(container->container()[ j ])) {
          isEqual = true;
        } 
      }
      // If an object is not found in the container
      // Then set the flag to false.
      if (!isEqual) {
        allObjectsFound = false;
      }
    } 
    // The feature fires if all the objects are found.
    if (allObjectsFound) {
      return !_invert;
    } else {
      return _invert;
    }
  }
  return false;
}



/** 
 * imports the Feature_Min_X_Container_Abstract_Container_Spatial_Relation class from an XML file
 */
void
Feature_Min_X_Container_Abstract_Container_Spatial_Relation::
from_xml( const string& filename ){
  xmlDoc * doc = NULL;
  xmlNodePtr root = NULL;
  doc = xmlReadFile( filename.c_str(), NULL, 0 );
  if( doc != NULL ){
    root = xmlDocGetRootElement( doc );
    if( root->type == XML_ELEMENT_NODE ){
      xmlNodePtr l1 = NULL;
      for( l1 = root->children; l1; l1 = l1->next ){
        if( l1->type == XML_ELEMENT_NODE ){
          if( xmlStrcmp( l1->name, ( const xmlChar* )
              ( "feature_min_x_container_abstract_container_spatial_relation" ) ) == 0 ){
            from_xml( l1 );
          }
        }
      }
      xmlFreeDoc( doc );
    }
  }
  return;
}

/** 
 * imports the Feature_Min_X_Container_Abstract_Container_Spatial_Relation class from an XML node pointer
 */
void
Feature_Min_X_Container_Abstract_Container_Spatial_Relation::
from_xml( xmlNodePtr root ){
  _invert = false;
  if( root->type == XML_ELEMENT_NODE ){
    xmlChar * tmp = xmlGetProp( root, ( const xmlChar* )( "invert" ) );
    if( tmp != NULL ){
      string invert_string = ( const char* )( tmp );
      _invert = ( bool ) ( strtol( invert_string.c_str(), NULL, 10 ) );
      xmlFree( tmp );
    }
    tmp = xmlGetProp( root, ( const xmlChar* )( "relation_type" ) );
    if( tmp != NULL){
      string relation_type_string = ( const char* )( tmp );
       _relation_type = relation_type_string ;
      xmlFree( tmp );
    }
  }
}


/**
 * exports the Feature_Min_X_Container_Abstract_Container_Spatial_Relation class to an XML file
 */
void
Feature_Min_X_Container_Abstract_Container_Spatial_Relation::
to_xml( const string& filename )const{
  xmlDocPtr doc = xmlNewDoc( ( xmlChar* )( "1.0" ) );
  xmlNodePtr root = xmlNewDocNode( doc, NULL, ( xmlChar* )( "root" ), NULL );
  xmlDocSetRootElement( doc, root );
  to_xml( doc, root );
  xmlSaveFormatFileEnc( filename.c_str(), doc, "UTF-8", 1 );
  xmlFreeDoc( doc );
  return;
}

/**
 * exports the Feature_Min_X_Container_Abstract_Container_Spatial_Relation class to an XML node pointer
 */
void
Feature_Min_X_Container_Abstract_Container_Spatial_Relation::
to_xml( xmlDocPtr doc,
        xmlNodePtr root )const{
  xmlNodePtr node = xmlNewDocNode( doc, NULL, ( xmlChar* )
                   ( "feature_min_x_container_abstract_container_spatial_relation" ), NULL );
  stringstream invert_string;
  invert_string << _invert;
  xmlNewProp( node, ( const xmlChar* )( "invert" ), ( const xmlChar* )( invert_string.str().c_str() ) );
  xmlNewProp( node, ( const xmlChar* )( "relation_type" ), ( const xmlChar* )( _relation_type ).c_str() );
  xmlAddChild( root, node );
  return;
}

namespace h2sl {
  /** 
   * Feature_Min_X_Container_Abstract_Container_Spatial_Relation class ostream operator
   */
  ostream&
  operator<<( ostream& out,
              const Feature_Min_X_Container_Abstract_Container_Spatial_Relation& other ){
   out << "class:\"Feature_Min_X_Container_Abstract_Container_Spatial_Relation\" ";
   out << "relation_type:\"" << other.relation_type()  << "\" ";
    return out;
  }
}

