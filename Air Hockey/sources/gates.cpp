//
//  gates.cpp
//  Air Hockey
//
//  Created by YuriySavchenko on 7/13/19.
//  Copyright © 2019 YuriySavchenko. All rights reserved.
//

#include "../headers/gates.h"

/* implementation of explicit constructor */
Gates::Gates(Borders &&borders, Point &&pos) :
    countGoals(0)
{
    this->borders = std::move(borders);
    this->rect.x = pos.x();
    this->rect.y = pos.y();
    initGates();
    displayGoals();
}

/* implementation of basic destructor */
Gates::~Gates()
{
    Mix_FreeMusic(music);
    SDL_FreeSurface(surface);
}

/* implementation of method which allows initialize Gates */
void Gates::initGates()
{
    music = Mix_LoadMUS("audio/goalsong.wav");
    font = TTF_OpenFont("fonts/Arial.ttf", 40);
}

/* implementation of method which allows play music when player beat a goal */
void Gates::playMusic()
{
    Mix_PlayMusic(music, 0);
}

/* implementation of method which allows display count of goals in gates like simple text */
void Gates::displayGoals()
{
    surface = TTF_RenderText_Solid(font, std::to_string(countGoals).c_str(), {255, 255, 255});
}

/* implementation of method for increase of goals in Gates */
void Gates::increaseGoals()
{
    countGoals++;
}

/* implementation of method for reseting of goals in Gates */
void Gates::resetGoals()
{
    countGoals = 0;
}

/* implementation of function which allows return object of SDL_Surface */
SDL_Surface *Gates::getSurface()
{
    return surface;
}

/* implementation of function which allows return object of SDL_Rect */
SDL_Rect *Gates::getRect()
{
    return &rect;
}

/* implementation of function which allows return borders of gates */
const Borders Gates::getBorders()
{
    return borders;
}
