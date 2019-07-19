//
//  Point.h
//  Air Hockey
//
//  Created by YuriySavchenko on 7/16/19.
//  Copyright © 2019 YuriySavchenko. All rights reserved.
//

#ifndef point_h
#define point_h

/**
 * \brief class which presents \b Point in the decart system of coordinates
 */
class Point {
private:
    int _x_;    ///< \e coordinate \b x
    int _y_;    ///< \e coordinate \b y
    
public:
    Point() = default;
    ~Point() = default;
    Point(int &&, int &&);      ///< explicit \e constructors
    
public:
    const int x();      ///< \e function which returns \b x \b coordinate
    const int y();      ///< \e function which returns \b y \b coordinate
};

#endif /* point_h */
