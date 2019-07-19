//
//  ball.cpp
//  Air Hockey
//
//  Created by YuriySavchenko on 7/13/19.
//  Copyright © 2019 YuriySavchenko. All rights reserved.
//

#include "../headers/ball.h"

/* implementation of typical constructor */
Ball::Ball()
{
    rect.x = 220;
    rect.y = 370;
    rect.h = 40;
    rect.w = 40;
    begin = std::move(Point {220, 370});
    radius = rect.w/2;
}

/* implementation of typical destructor */
Ball::~Ball()
{
    Mix_FreeMusic(music);
    //delete surface;
    SDL_FreeSurface(surface);
}

/* implementation of explicit constructor */
Ball::Ball(const int &x, const int &y, const int &w, const int &h)
{
    rect.x = x;
    rect.y = y;
    rect.h = h;
    rect.w = w;
}

/* implementation of method for initialization of Ball */
void Ball::initBall()
{
    surface = IMG_Load("images/ball.bmp");
    music = Mix_LoadMUS("audio/ballkickboard.wav");
}

/* implementation of method for playing music when ball touch board */
void Ball::playMusic()
{
    Mix_PlayMusic(music, 0);
}

/* implementation of function which allows return value of rect */
SDL_Rect *Ball::getRect()
{
    return &rect;
}

/* implementation of function which allows return SDL for ball */
SDL_Surface *Ball::getSurface()
{
    return surface;
}

/* implementation of function which allows return radius of ball */
const int Ball::R()
{
    return radius;
}

/* implementation of method for moving of ball */
void Ball::moveBall(const int &x, const int &y)
{
    this->rect.x = x;
    this->rect.y = y;
}

/* implementation of method for moving of Ball to start position */
void Ball::moveToBegin()
{
    rect.x = begin.x();
    rect.y = begin.y();
}
