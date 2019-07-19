//
//  realplayer.cpp
//  Air Hockey
//
//  Created by YuriySavchenko on 7/15/19.
//  Copyright © 2019 YuriySavchenko. All rights reserved.
//

#include "realplayer.h"

/* implementation of explicit constructor */
RealPlayer::RealPlayer(const std::string &name, std::unique_ptr<Brassy> &brassyPtr, std::unique_ptr<Gates> &gatesPtr)
{
    this->name = name;
    this->brassy = std::move(brassyPtr);
    this->gates = std::move(gatesPtr);
    brassy->initBrassy();
}

/* implementation of function for manipulation of brassy */
void RealPlayer::manipulate(SDL_Event &event)
{
    Point leftUpPoint = static_cast<Point>(static_cast<Borders>(brassy->getBorders()).getLeftUpPoint());
    Point rightUpPoint = static_cast<Point>(static_cast<Borders>(brassy->getBorders()).getRightUpPoint());
    Point rightDownPoint = static_cast<Point>(static_cast<Borders>(brassy->getBorders()).getRightDownPoint());
    
    if ((event.button.x > leftUpPoint.x()) && (event.button.x < rightUpPoint.x()))
        if ((event.button.y < rightDownPoint.y()) && (event.button.y > rightUpPoint.y()))
            brassy->moveBrassy(event.button.x, event.button.y);
}

/* implementation of function which allows return ptr on the Brassy object */
std::unique_ptr<Brassy> &RealPlayer::getBrassy()
{
    return brassy;
}

/* implementation of function which allows return ptr on the Gates object */
std::unique_ptr<Gates> &RealPlayer::getGates()
{
    return gates;
}

/* implementation of function which allows return name of user */
std::string RealPlayer::getName()
{
    return name;
}
