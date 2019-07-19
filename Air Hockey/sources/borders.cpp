//
//  borders.cpp
//  Air Hockey
//
//  Created by YuriySavchenko on 7/16/19.
//  Copyright © 2019 YuriySavchenko. All rights reserved.
//

#include "../headers/borders.h"

/* implementation of explicit constructor */
Borders::Borders(Point &&point1,  Point &&point2, Point &&point3, Point &&point4) :
    pointLeftUp(point1), pointLeftDown(point2), pointRightUp(point3), pointRightDown(point4)
{
    
}

/* implementation of function which allows return value for point in left upper side */
const Point Borders::getLeftUpPoint()
{
    return pointLeftUp;
}

/* implementation of function which allows return value for point in left low side */
const Point Borders::getLeftDownPoint()
{
    return pointLeftDown;
}

/* implementation of function which allows return value for point in right upper side */
const Point Borders::getRightUpPoint()
{
    return pointRightUp;
}

/* implementation of function which allows return value for point in right low side */
const Point Borders::getRightDownPoint()
{
    return pointRightDown;
}
