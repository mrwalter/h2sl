/**
 * @file object_type.cc
 *
 * @brief
 *
 * a class that describes a object_type
 */

#include "h2sl/object_type.h"

using namespace std;
using namespace h2sl;

/**
 * Object_Type class constructor
 */
Object_Type::
Object_Type( const string& objectType ) : Grounding() {
  insert_prop< std::string >( _properties, "object_type", objectType );
}


Object_Type::
Object_Type( xmlNodePtr root ) : Grounding() {
    insert_prop< std::string >( _properties, "object_type", "na" );
    from_xml( root );
}


/**
 * Object_Type class copy constructor
 */
Object_Type::
Object_Type( const Object_Type& other ) : Grounding( other ) {

}

/**
 * Object_Type class destructor
 */
Object_Type::
~Object_Type() {

}

/** 
 * Object_Type class assignment operator
 */
Object_Type&
Object_Type::
operator=( const Object_Type& other ){
  _properties = other._properties;
  return (*this);
}

/** 
 * Object_Type class equality operator
 */
bool
Object_Type::
operator==( const Object_Type& other )const{
  if ( type() != other.type() ){
    return false;
  } else {
    return true;
  }
}

/** 
 * Object_Type class inequality operator
 */
bool
Object_Type::
operator!=( const Object_Type& other )const{
  return !( *this == other );
}

/** 
 * Object_Type class dup operator
 */
Object_Type*
Object_Type::
dup( void )const{
  return new Object_Type( *this );
}

/** 
 * imports the Object_Type class from an XML file
 */
void
Object_Type::
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
          if( xmlStrcmp( l1->name, ( const xmlChar* )( "object_type" ) ) == 0 ){
            from_xml( l1 );
          }
        }
      }
      xmlFreeDoc( doc );
    } else {
      xmlFreeDoc( doc );
    }
  }
  return;
}

/** 
 * imports the Object_Type class from an XML node pointer
 */
void
Object_Type::
from_xml( xmlNodePtr root ){
  type() = "na";
  if( root->type == XML_ELEMENT_NODE ){
      pair< bool, string > object_type_prop = has_prop< std::string >( root, "object_type" );
      if( object_type_prop.first ){
        type() = object_type_prop.second;
      }
  }
  return;
}

/**
 * exports the Object_Type class to an XML file
 */
void
Object_Type::
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
 * exports the Object_Type class to an XML node pointer
 */
void
Object_Type::
to_xml( xmlDocPtr doc,
        xmlNodePtr root )const{
  xmlNodePtr node = xmlNewDocNode( doc, NULL, ( xmlChar* )( "object_type" ), NULL );
  xmlNewProp( node, ( const xmlChar* )( "object_type" ), ( const xmlChar* )( get_prop< std::string >( _properties, "object_type").c_str() ) );
  xmlAddChild( root, node );
  return;
}

namespace h2sl {
  /** 
   * Object_Type class ostream operator
   */
  ostream&
  operator<<( ostream& out,
              const Object_Type& other ){
    out << "class:\"Object_Type\" ";
    out << "object_type:" << other.type() << " ";
    return out;
  }
}
