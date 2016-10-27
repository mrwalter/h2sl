/**
 * @file    world.h
 * @author  Thomas M. Howard (tmhoward@csail.mit.edu)
 *          Matthew R. Walter (mwalter@csail.mit.edu)
 * @version 1.0
 *
 * @section LICENSE
 *
 * This file is part of h2sl.
 *
 * Copyright (C) 2014 by the Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see
 * <http://www.gnu.org/licenses/gpl-2.0.html> or write to the Free
 * Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 * @section DESCRIPTION
 *
 * The interface for a class used to represent the world
 */

#ifndef H2SL_WORLD_H
#define H2SL_WORLD_H

#include <iostream>
#include <vector>

#include "h2sl/object.h"

namespace h2sl {
  class World {
  public:
    World( const unsigned long long& time = 0, const std::vector< Object* >& objects = std::vector< Object* >() );
    virtual ~World();
    World( const World& other );
    World& operator=( const World& other );
    virtual World* dup( void )const;

    virtual void to_xml( const std::string& filename )const;
    virtual void to_xml( xmlDocPtr doc, xmlNodePtr root )const;
    virtual void from_xml( const std::string& filename );
    virtual void from_xml( xmlNodePtr root );
  
    //virtual void convert_models( xmlNodePtr root );
    virtual void sort(void);
    
    static bool min_x_sort( const Object* a, const Object* b );
    static bool max_x_sort( const Object* a, const Object* b );
    static void min_x_sort_objects( std::vector< Object* >& objects );
    static void max_x_sort_objects( std::vector< Object* >& objects );
    static bool min_y_sort( const Object* a, const Object* b );
    static bool max_y_sort( const Object* a, const Object* b );
    static void min_y_sort_objects( std::vector< Object* >& objects );
    static void max_y_sort_objects( std::vector< Object* >& objects );
    static bool min_abs_y_sort( const Object* a, const Object* b );
    static bool max_abs_y_sort( const Object* a, const Object* b );
    static bool min_z_sort( const Object* a, const Object* b );
    static bool max_z_sort( const Object* a, const Object* b );
    static bool min_distance_sort( const Object* a, const Object* b );
    static bool max_distance_sort( const Object* a, const Object* b );
    static void min_distance_sort_objects( std::vector< Object* >& objects );
    static void max_distance_sort_objects( std::vector< Object* >& objects );
    static void min_center_distance_sort_objects( std::vector< Object* >& objects );
    static void max_center_distance_sort_objects( std::vector< Object* >& objects );
      

    inline unsigned long long& time( void ){ return _time; };
    inline const unsigned long long& time( void )const{ return _time; };
    inline std::vector< Object* >& objects( void ){ return _objects; };
    
    inline const std::vector< Object* >& objects( void )const{ return _objects; };
    inline const std::vector< std::vector< Object* > >& min_x_sorted_objects( void )const{ return _min_x_sorted_objects; };
    inline const std::vector< std::vector< Object* > >& max_x_sorted_objects( void )const{ return _max_x_sorted_objects; };
    inline const std::vector< std::vector< Object* > >& min_y_sorted_objects( void )const{ return _min_y_sorted_objects; };
    inline const std::vector< std::vector< Object* > >& max_y_sorted_objects( void )const{ return _max_y_sorted_objects; };
    inline const std::vector< std::vector< Object* > >& min_abs_y_sorted_objects( void )const{ return _min_abs_y_sorted_objects; };
    inline const std::vector< std::vector< Object* > >& max_abs_y_sorted_objects( void )const{ return _max_abs_y_sorted_objects; };
    inline const std::vector< std::vector< Object* > >& min_z_sorted_objects( void )const{ return _min_z_sorted_objects; };
    inline const std::vector< std::vector< Object* > >& max_z_sorted_objects( void )const{ return _max_z_sorted_objects; };
    inline const std::vector< std::vector< Object* > >& min_distance_sorted_objects( void )const{ return _min_distance_sorted_objects; };
    inline const std::vector< std::vector< Object* > >& max_distance_sorted_objects( void )const{ return _max_distance_sorted_objects; };
    inline const std::vector< std::vector< Object* > >& min_center_distance_sorted_objects( void )const{ return _min_center_distance_sorted_objects; };
    inline const std::vector< std::vector< Object* > >& max_center_distance_sorted_objects( void )const{ return _max_center_distance_sorted_objects; };
      

  protected:
    std::vector< Object* > _objects;
    std::vector< std::vector< Object* > > _min_x_sorted_objects;
    std::vector< std::vector< Object* > > _max_x_sorted_objects;
    std::vector< std::vector< Object* > > _min_y_sorted_objects;
    std::vector< std::vector< Object* > > _max_y_sorted_objects;
    std::vector< std::vector< Object* > > _min_abs_y_sorted_objects;
    std::vector< std::vector< Object* > > _max_abs_y_sorted_objects;
    std::vector< std::vector< Object* > > _min_z_sorted_objects;
    std::vector< std::vector< Object* > > _max_z_sorted_objects;
    std::vector< std::vector< Object* > > _min_distance_sorted_objects;
    std::vector< std::vector< Object* > > _max_distance_sorted_objects;
    std::vector< std::vector< Object* > > _min_center_distance_sorted_objects;
    std::vector< std::vector< Object* > > _max_center_distance_sorted_objects;
    unsigned long long _time;

  private:

  };
  std::ostream& operator<<( std::ostream& out, const World& other );
}

#endif /* H2SL_WORLD_H */
