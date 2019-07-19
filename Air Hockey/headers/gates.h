//
//  gates.h
//  Air Hockey
//
//  Created by YuriySavchenko on 7/13/19.
//  Copyright © 2019 YuriySavchenko. All rights reserved.
//

#ifndef gates_h
#define gates_h

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include "borders.h"
#include "point.h"

/**
 * \brief class which presents \b Gates and allows count of \a goals
 */
class Gates {
private:
    int countGoals;         ///< \e variable which allows save count of \b goals
    Mix_Music *music;       ///< \e variable which allows save \b music
    SDL_Surface *surface;   ///< \e variable which allows save \b surface
    TTF_Font *font;         ///< \e variable which allows save \b font
    SDL_Rect rect;          ///< \e variable which allows save \b rect
    Borders borders;        ///< \e variable which allows save \b borders
    
public:
    Gates() = default;
    Gates(Borders &&, Point &&);
    ~Gates();
    
public:
    void initGates();       ///< \e method for initialization of \b Gates
    void playMusic();       ///< \e method for playing \b music
    void displayGoals();    ///< \e method for displaying \a count of \b goals
    void increaseGoals();   ///< \e method for increase of \b goals
    void resetGoals();      ///< \e method for reseting of \b goals
    
public:
    SDL_Surface *getSurface();      ///< \e function for returning \a object of \b SDL_Surface
    SDL_Rect *getRect();            ///< \e function for returning \a object of \b SDL_Rect
    const Borders getBorders();     ///< \e function for returning \b Borders
};

#endif /* gates_h */
