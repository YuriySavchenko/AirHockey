//
//  brassy.h
//  Air Hockey
//
//  Created by YuriySavchenko on 7/13/19.
//  Copyright © 2019 YuriySavchenko. All rights reserved.
//

#ifndef brassy_h
#define brassy_h

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include "borders.h"
#include "point.h"

/**
 * \brief class which presents \b brassy for \b game
 */
class Brassy {
private:
    SDL_Rect rect;                      ///< \e variable for saving \b rect with start properties
    SDL_Surface *surface;               ///< \e variable for saving \b Brassy
    Mix_Music *music;                   ///< \e variable for saving \b music of kick
    Borders borders;                    ///< \e variable for saving \b Borders
    int radius;
    
public:
    Brassy() = default;
    Brassy(const int &, const int &, const int &, const int &);     ///< explicit \e constructor
    ~Brassy();      ///< typical \e destructor
    
public:
    void initBrassy();                              ///< \e method for initialization of \b brassy
    void playMusic();                               ///< \e method for playing \b music
    void moveBrassy(const int &, const int &);      ///< \e method for changing position of \b brassy
    void setBorders(Borders &&);                    ///< \e method for setting \b borders for \b brassy
    
public:
    SDL_Rect *getRect();            ///< \e function for returning object of \b SDL_Rect
    SDL_Surface *getSurface();      ///< \e function for returning object of \b SDL_Surface
    const Borders getBorders();     ///< \e function for returning \a field \b borders
    const int R();
};

#endif /* brassy_h */
