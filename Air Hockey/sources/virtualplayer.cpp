//
//  virtualplayer.cpp
//  Air Hockey
//
//  Created by YuriySavchenko on 7/15/19.
//  Copyright © 2019 YuriySavchenko. All rights reserved.
//

#include "../headers/virtualplayer.h"

/* implementation of explicit constructor */
VirtualPlayer::VirtualPlayer(std::unique_ptr<Brassy> &brassyPtr, std::unique_ptr<Gates> &gatesPtr) :
    directionMove(1)
{
    this->name = "Computer";
    this->brassy = std::move(brassyPtr);
    this->gates = std::move(gatesPtr);
    this->brassy->initBrassy();
}

/* implementation of method for manipulating of brassy by computer */
void VirtualPlayer::manipulate(SDL_Event &event)
{
    Point leftDownPoint = static_cast<Point>(static_cast<Borders>(brassy->getBorders()).getLeftDownPoint());
    Point rightDownPoint = static_cast<Point>(static_cast<Borders>(brassy->getBorders()).getRightDownPoint());
    
    if (brassy->getRect()->x == rightDownPoint.x()) {
        directionMove = 2;
    }
    else if (brassy->getRect()->x == leftDownPoint.x()) {
        directionMove = 1;
    }
    
    if (directionMove == 1)
        brassy->moveBrassy(brassy->getRect()->x+2, brassy->getRect()->y);
    else if (directionMove == 2)
        brassy->moveBrassy(brassy->getRect()->x-2, brassy->getRect()->y);
}

/* implementation of function which allows return ptr on the Brassy object */
std::unique_ptr<Brassy> &VirtualPlayer::getBrassy()
{
    return brassy;
}

/* implementation of function which allows return ptr on the Gates object  */
std::unique_ptr<Gates> &VirtualPlayer::getGates()
{
    return gates;
}

/* implementation of function which allows return name of user */
std::string VirtualPlayer::getName()
{
    return name;
}
