/**
 * @file feature_abstract_container_number.cc
 *
 * @brief
 *
 * Class used to describe a feature of the abstract_container number
 */
#include <sstream>

#include "h2sl/feature_abstract_container_number.h"
#include "h2sl/number.h"
#include "h2sl/abstract_container.h"

using namespace std;
using namespace h2sl;

/**
 * Feature_Abstract_Container_Number class constructor
 */
Feature_Abstract_Container_Number::
Feature_Abstract_Container_Number( const bool& invert,
                          const std::string& abstract_container_number ) : Feature( invert ),
                                                              _abstract_container_number( abstract_container_number ) {

}

/**
 * Feature_Abstract_Container_Number class copy constructor
 */
Feature_Abstract_Container_Number::
Feature_Abstract_Container_Number( const Feature_Abstract_Container_Number& other ) : Feature( other ),
                                                              _abstract_container_number( other._abstract_container_number ){

}

/**
 * Feature_Abstract_Container_Number class destructor
 */
Feature_Abstract_Container_Number::
~Feature_Abstract_Container_Number() {

}

/** 
 * Feature_Abstract_Container_Number class assignment operator
 */
Feature_Abstract_Container_Number&
Feature_Abstract_Container_Number::
operator=( const Feature_Abstract_Container_Number& other ){
  _invert = other._invert;
  _abstract_container_number = other._abstract_container_number;
  return (*this);
}

/**
 * returns the value of the fature
 */
bool
Feature_Abstract_Container_Number::
value( const unsigned int& cv,
        const Grounding* grounding,
        const vector< pair< const Phrase*, vector< Grounding* > > >& children,
        const Phrase* phrase,
        const World* world ){
  return value( cv, grounding, children, phrase, world, NULL );
}

bool
Feature_Abstract_Container_Number::
value( const unsigned int& cv,
        const Grounding* grounding,
        const vector< pair< const Phrase*, vector< Grounding* > > >& children,
        const Phrase* phrase,
        const World* world,
        const Grounding* context ){
  const Abstract_Container* abstract_container = dynamic_cast< const Abstract_Container* >( grounding );
  if( abstract_container != NULL ){
    if( abstract_container->number() == _abstract_container_number ){
      return !_invert;
    } else {
      return _invert;
    }
  }
  return false;
}

/** 
 * imports the Feature_Abstract_Container_Number class from an XML file
 */
void
Feature_Abstract_Container_Number::
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
          if( xmlStrcmp( l1->name, ( const xmlChar* )( "feature_abstract_container_number" ) ) == 0 ){
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
 * imports the Feature_Abstract_Container_Number class from an XML node pointer
 */
void
Feature_Abstract_Container_Number::
from_xml( xmlNodePtr root ){
  _invert = false;
  _abstract_container_number = "na";
  if( root->type == XML_ELEMENT_NODE ){
    xmlChar * tmp = xmlGetProp( root, ( const xmlChar* )( "invert" ) );
    if( tmp != NULL ){
      string invert_string = ( const char* )( tmp );
      _invert = ( bool ) ( strtol( invert_string.c_str(), NULL, 10 ) );
      xmlFree( tmp );
    }
    tmp = xmlGetProp( root, ( const xmlChar* )( "abstract_container_number" ) );
    if( tmp != NULL){
      string abstract_container_number_string = ( const char* )( tmp );
      _abstract_container_number = abstract_container_number_string;
      xmlFree( tmp );
    }
  }
}

/**
 * exports the Feature_Abstract_Container_Number class to an XML file
 */
void
Feature_Abstract_Container_Number::
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
 * exports the Feature_Abstract_Container_Number class to an XML node pointer
 */
void
Feature_Abstract_Container_Number::
to_xml( xmlDocPtr doc,
        xmlNodePtr root )const{
  xmlNodePtr node = xmlNewDocNode( doc, NULL, ( xmlChar* )( "feature_abstract_container_number" ), NULL );
  stringstream invert_string;
  invert_string << _invert;
  xmlNewProp( node, ( const xmlChar* )( "invert" ), ( const xmlChar* )( invert_string.str().c_str() ) );
  xmlNewProp( node, ( const xmlChar* )( "abstract_container_number" ), ( const xmlChar* )( _abstract_container_number.c_str() ) );
  xmlAddChild( root, node );
  return;
}

std::string&
Feature_Abstract_Container_Number::
abstract_container_number( void ){
  return _abstract_container_number;
}

const std::string&
Feature_Abstract_Container_Number::
abstract_container_number( void )const{
  return _abstract_container_number;
}

namespace h2sl {
  /** 
   * Feature_Abstract_Container_Number class ostream operator
   */
  ostream&
  operator<<( ostream& out,
              const Feature_Abstract_Container_Number& other ){
    out << "class:\"Feature_Abstract_Container_Number\" ";
    out << "abstract_container_number:\"" << other.abstract_container_number() << "\"";
    return out;
  }
}
