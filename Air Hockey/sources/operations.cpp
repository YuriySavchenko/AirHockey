//
//  distance.cpp
//  Air Hockey
//
//  Created by Yurii Savchenko on 7/18/19.
//  Copyright © 2019 YuriySavchenko. All rights reserved.
//

#include "../headers/operations.h"

/* implementation of function which allows return distance between two points */
double Operations::distance(Point &&point1, Point &&point2)
{
    return sqrt(pow((point2.x()-point1.x()), 2) + pow((point2.y()-point1.y()), 2));
}

/* implementation of function which allows return angle between two lines */
double Operations::angle(double against, double hypotenuse)
{
    return (asin(static_cast<double>(against/hypotenuse))*180)/M_PI;
}
