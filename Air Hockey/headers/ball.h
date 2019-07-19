//
//  ball.h
//  Air Hockey
//
//  Created by YuriySavchenko on 7/13/19.
//  Copyright © 2019 YuriySavchenko. All rights reserved.
//

#ifndef ball_h
#define ball_h

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "point.h"

/**
 * \brief class which presents \b ball for \b game
 */
class Ball {
private:
    SDL_Rect rect;                      ///< \e variable for saving \b rect with start properties
    SDL_Surface *surface;               ///< \e variable for saving \b ball
    Mix_Music *music;                   ///< \e variable for saving \b music
    Point begin;                        ///< \e variable for saving point of start \b position
    int radius;                         ///< \e variable for saving \a radius of \b ball
    
public:
    Ball();                                                     ///< ypical \e constructor
    ~Ball();                                                    ///< typical \e destructor
    Ball(const int &, const int &, const int &, const int &);   ///< explicit \e constructor
    
public:
    void initBall();                            ///< \e method for initialization of \b ball
    void playMusic();                           ///< \e method for playing music 
    void moveBall(const int &, const int &);    ///< \e method for changing position of \b ball
    void moveToBegin();                         ///< \e method for moving \b ball to start \a position
    
public:
    SDL_Rect *getRect();            ///< \e function for returning \a object of \b SDL_Rect
    SDL_Surface *getSurface();      ///< \e function for returning \a object of \b SDL_Surface
    const int R();                  ///< \e function for returning \a radius of \b Ball
};

#endif /* ball_h */
