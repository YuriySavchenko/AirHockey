//
//  distance.h
//  Air Hockey
//
//  Created by Yurii Savchenko on 7/18/19.
//  Copyright © 2019 YuriySavchenko. All rights reserved.
//

#ifndef operations_h
#define operations_h

#include "point.h"
#include "math.h"

/**
 * \brief class which presents necessary mathematical \b operations
 */
class Operations {
public:
    static double distance(Point &&, Point &&);     ///< \e function which returns \b distance between two \a points
    static double angle(double, double);            ///< \e function which returns \b angle in \a degrees between two lines
};

#endif /* operations_h */
