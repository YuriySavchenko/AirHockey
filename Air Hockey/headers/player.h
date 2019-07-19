//
//  player.h
//  Air Hockey
//
//  Created by YuriySavchenko on 7/13/19.
//  Copyright © 2019 YuriySavchenko. All rights reserved.
//

#ifndef player_h
#define player_h

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "gates.h"
#include "brassy.h"

/**
 * \brief abstract class which presents /b Player
 */
class Player {
protected:
    std::unique_ptr<Brassy> brassy;     ///< \e unique_ptr for saving object of \b Brassy
    std::unique_ptr<Gates> gates;       ///< \e unique_ptr for saving object of \b Gates
    std::string name;                   ///< \e variable for saving \a name of \b Player

public:
    virtual void manipulate(SDL_Event &) = 0;      ///< virtual \e method for manipulating of \b Brassy
};

#endif /* player_h */
