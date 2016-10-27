/**
 * @file feature_is_region_container.cc
 *
 * @brief
 *
 * Class used to describe a feature object matches child type
 */

#include <assert.h>
#include <sstream>

#include "h2sl/feature_is_region_container.h"
#include "h2sl/region_container.h"

using namespace std;
using namespace h2sl;

/**
 * Feature_Is_Region_Container class constructor
 */
Feature_Is_Region_Container::
Feature_Is_Region_Container( const bool& invert ) : Feature( invert ) {
    
}

/**
 * Feature_Is_Region_Container class destructor
 */
Feature_Is_Region_Container::
~Feature_Is_Region_Container() {
    
}

/**
 * Feature_Is_Region_Container class copy constructor
 */
Feature_Is_Region_Container::
Feature_Is_Region_Container( const Feature_Is_Region_Container& other ) : Feature( other ) {
    
}

/**
 * Feature_Is_Region_Container class assignment operator
 */
Feature_Is_Region_Container&
Feature_Is_Region_Container::
operator=( const Feature_Is_Region_Container& other ) {
    _invert = other._invert;
    return (*this);
}

/**
 * returns the value of the feature.
 */
bool
Feature_Is_Region_Container::
value( const unsigned int& cv,
      const h2sl::Grounding* grounding,
      const vector< pair< const h2sl::Phrase*, vector< h2sl::Grounding* > > >& children,
      const h2sl::Phrase* phrase,
      const World* world ){
    const Region_Container * region_container = dynamic_cast< const Region_Container* >( grounding );
    if( region_container != NULL ){
      return !_invert;
    } else {
      return _invert;
    }
}

/**
 * exports the Feature_Is_Region_Container class to an XML file
 */
void
Feature_Is_Region_Container::
to_xml( xmlDocPtr doc, xmlNodePtr root )const{
    xmlNodePtr node = xmlNewDocNode( doc, NULL, ( xmlChar* )( "feature_is_region_container" ), NULL );
    stringstream invert_string;
    invert_string << _invert;
    xmlNewProp( node, ( const xmlChar* )( "invert" ), ( const xmlChar* )( invert_string.str().c_str() ) );
    xmlAddChild( root, node );
    return;
}

/**
 * imports the Feature_Is_Region_Container class from an XML file
 */
void
Feature_Is_Region_Container::
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
     * Feature_Is_Region_Container class ostream operator
     */
    ostream&
    operator<<( ostream& out,
               const Feature_Is_Region_Container& other ) {
	out << "class:\"Feature_Is_Region_Container\" ";
        return out;
    }
    
}
