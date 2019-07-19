//
//  point.cpp
//  Air Hockey
//
//  Created by YuriySavchenko on 7/16/19.
//  Copyright © 2019 YuriySavchenko. All rights reserved.
//

#include "../headers/point.h"

/* implementation of explicit constructor */
Point::Point(int &&x, int &&y) :
    _x_(x), _y_(y)
{
    
}

/* implementation of function which allows return value for x coordinate */
const int Point::x()
{
    return _x_;
}

/* implementation of function which allows return value for y coordinate */
const int Point::y()
{
    return _y_;
}
