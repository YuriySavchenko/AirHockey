//
//  brassy.cpp
//  Air Hockey
//
//  Created by YuriySavchenko on 7/13/19.
//  Copyright © 2019 YuriySavchenko. All rights reserved.
//

#include "../headers/brassy.h"

/* implementation of basic destructor */
Brassy::~Brassy()
{
    SDL_FreeSurface(surface);
    Mix_FreeMusic(music);
}

/* implementation of explicit constructor */
Brassy::Brassy(const int &x, const int &y, const int &h, const int &w)
{
    rect.x = x;
    rect.y = y;
    rect.h = h;
    rect.w = w;
    radius = w/2;
}

/* implementation of method which allows initialize brassy */
void Brassy::initBrassy()
{
    surface = IMG_Load("images/brassy.bmp");
    music = Mix_LoadMUS("audio/brassykickball.wav");
}

/* implementation of method which allows play music when brassy touch ball */
void Brassy::playMusic()
{
    Mix_PlayMusic(music, 0);
}

/* implementation of method for changing position of brassy */
void Brassy::moveBrassy(const int &x, const int &y)
{
    this->rect.x = x;
    this->rect.y = y;
}

/* implementation of function which returns SDL_Rect */
SDL_Rect *Brassy::getRect()
{
    return &rect;
}

/* implementation of function which returns SDL_Surface */
SDL_Surface *Brassy::getSurface()
{
    return surface;
}

/* implementation of function which allows return borders */
const Borders Brassy::getBorders()
{
    return borders;
}

/* implementation of method which allows set borders */
void Brassy::setBorders(Borders &&borders)
{
    this->borders = borders;
}

/* implementation of function which allows return radius of brassy */
const int Brassy::R()
{
    return radius;
}
