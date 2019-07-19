//
//  board.h
//  Air Hockey
//
//  Created by YuriySavchenko on 7/12/19.
//  Copyright © 2019 YuriySavchenko. All rights reserved.
//

#ifndef board_h
#define board_h

#include <iostream>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "ball.h"
#include "brassy.h"
#include "gates.h"
#include "virtualplayer.h"
#include "realplayer.h"
#include "engine.h"
#include "borders.h"
#include "point.h"

/**
 * \brief class which presents \b board for \b game
 */
class Board {
private:
    const int boardWidth;          ///< \e variable for saving \b width of \b Board
    const int boardHeight;         ///< \e variable for saving \b height of \b Board
    
    SDL_Surface *background;        ///< \e variable for saving \b background
    SDL_Surface *board;             ///< \e variable for saving \b board
    
    SDL_Window *window;             ///< \e variable for saving \b window for \b game
    Mix_Music *music;               ///< \e variable for saving \b music
    SDL_Event event;                ///< \e variable for saving \b event of \b Board
    
private:
    std::unique_ptr<Engine> engine;     ///< \e unique_ptr for saving object of \b engine for \b Game
    std::shared_ptr<Ball> ball;         ///< \e unique_ptr for saving \b ball object
    std::shared_ptr<VirtualPlayer> virtualPlayer;   ///< \e unique_ptr for saving \b virtual \b Player
    std::shared_ptr<RealPlayer> realPlayer;         ///< \e unique_ptr for saving \b real \b Player

public:
    Board();                            ///< \e constructor without parameters
    ~Board();                           ///< typical \e destructor
    Board(const int &, const int &);    ///< explicit \e constructor with two parameters
    
public:
    void initBoard();      ///< \e method for initialization of \b Board
    void playMusic();      ///< \e method for playing \b music
    void updateBoard();    ///< \e method for updating state of \b Board
    void drawBoard();      ///< \e method for drawing \b Board
    void closeBoard();     ///< \e method for closing \b Board
    
public:
    const int getBoardWidth();      ///< \e function which allows return \b width of Board
    const int getBoardHeight();     ///< \e function which allows return \b height of Board
};

#endif /* board_h */
