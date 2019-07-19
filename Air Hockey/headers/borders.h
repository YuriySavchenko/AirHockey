//
//  Header.h
//  Air Hockey
//
//  Created by YuriySavchenko on 7/16/19.
//  Copyright © 2019 YuriySavchenko. All rights reserved.
//

#ifndef borders_h
#define borders_h

#include "point.h"

/**
 * \brief class which presents \b Borders for particular \a zone
 */
class Borders {
private:
    Point pointLeftUp;      ///< \e point in \a left \a upper \b side
    Point pointLeftDown;    ///< \e point in \a left \a low \b side
    Point pointRightUp;     ///< \e point in \a right \a upper \b side
    Point pointRightDown;   ///< \e point in \a right \a low \b side
    
public:
    Borders() = default;
    ~Borders() = default;
    Borders(Point &&, Point &&, Point &&, Point &&);    ///< explicit \e constructor
    
public:
    const Point getLeftUpPoint();       ///< \e function which returns \b Point in \a left \a upper \a side
    const Point getLeftDownPoint();     ///< \e function which returns \b Point in \a left \a low \a side
    const Point getRightUpPoint();      ///< \e function which returns \b Point in \a right \a upper \a side
    const Point getRightDownPoint();    ///< \e function which returns \b Point in \a right \a low \a side
};

#endif /* borders_h */
