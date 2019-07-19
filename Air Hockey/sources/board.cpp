//
//  board.cpp
//  Air Hockey
//
//  Created by YuriySavchenko on 7/12/19.
//  Copyright © 2019 YuriySavchenko. All rights reserved.
//

#include "../headers/board.h"

/* implementation of basic constructor */
Board::Board() :
    boardWidth(480), boardHeight(781)
{
    ball = std::make_shared<Ball>();
}

/* implementation of basic destructor */
Board::~Board()
{
    SDL_FreeSurface(board);
    SDL_FreeSurface(background);
    Mix_FreeMusic(music);
    SDL_DestroyWindow(window);
}

/* implementation of explicit constructor */
Board::Board(const int &width, const int &height) :
    boardWidth(width), boardHeight(height)
{
    ball = std::make_shared<Ball>();
}

/* implementation of method for initialization of Board */
void Board::initBoard()
{

    window = SDL_CreateWindow("Air Hockey v1.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, boardWidth, boardHeight, SDL_WINDOW_ALLOW_HIGHDPI);
    board = SDL_GetWindowSurface(window);
    
    if (window == nullptr) {
        std::cout << "[!] Error of creation window! Error { " << SDL_GetError() << " }" << std::endl;
    }
    
    background = IMG_Load("images/board.bmp");
    music = Mix_LoadMUS("audio/startgame.wav");
    
    if (background == nullptr) {
        std::cout << "[!] Error of BMP loading! Error { " << SDL_GetError() << " }" << std::endl;
    }
    
    ball->initBall();
    playMusic();
    
    std::unique_ptr<Brassy> brassyRealPlayer { new Brassy(300, 560, 60, 60) };
    std::unique_ptr<Brassy> brassyVirtualPlayer { new Brassy(90, 100, 60, 60) };
    Borders bordersGatesRealPlayer {Point {130, boardHeight-51}, Point {130, boardHeight+0}, Point {350, boardHeight-51}, Point {350, boardHeight+0}};
    Borders bordersGatesVirtualPlayer {Point {130, 10}, Point {130, 10}, Point {350, 10}, Point {350, 10}};
    Point posScoreRealPlayer {234, 740};
    Point posScoreVirtualPlayer {234, 0};
    std::unique_ptr<Gates> gatesRealPlayer { new Gates(std::move(bordersGatesRealPlayer), std::move(posScoreRealPlayer)) };
    std::unique_ptr<Gates> gatesVirtualPlayer { new Gates(std::move(bordersGatesVirtualPlayer), std::move(posScoreVirtualPlayer)) };
    
    brassyRealPlayer->setBorders(Borders {Point {10, 350}, Point {10, 681}, Point {350, 350}, Point {350, 681}});
    brassyVirtualPlayer->setBorders(Borders {Point {10, 10}, Point {10, 350}, Point {350, 10}, Point {350, 350}});
    
    virtualPlayer = std::make_shared<VirtualPlayer>(brassyVirtualPlayer, gatesVirtualPlayer);
    realPlayer = std::make_shared<RealPlayer>("User", brassyRealPlayer, gatesRealPlayer);
    Borders borders {Point {10, 10}, Point {10, boardHeight-10}, Point {boardWidth-10, 10}, Point {boardWidth-10, boardHeight-10}};
    engine = std::make_unique<Engine>(std::move(borders), ball, realPlayer, virtualPlayer);
}

/* implementation of method which allows play music when game will start */
void Board::playMusic()
{
    Mix_PlayMusic(music, 0);
}

/* implementation of method for updating state of Board */
void Board::updateBoard()
{
    bool stateBoard = true;
    
    while (stateBoard) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                stateBoard = false;
                closeBoard();
                break;
            }
            
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                engine->resetScores();
            }
            
            if (event.type == SDL_MOUSEMOTION) {
                realPlayer->manipulate(event);
            }
        }
        
        engine->handling();
        drawBoard();
        virtualPlayer->manipulate(event);
        virtualPlayer->getGates()->displayGoals();
        realPlayer->getGates()->displayGoals();
    }
}

/* implementation of method for drawing Board */
void Board::drawBoard()
{
    SDL_BlitSurface(background, nullptr, board, nullptr);
    SDL_BlitSurface(ball->getSurface(), nullptr, board, ball->getRect());
    SDL_BlitSurface(virtualPlayer->getBrassy()->getSurface(), nullptr, board, virtualPlayer->getBrassy()->getRect());
    SDL_BlitSurface(realPlayer->getBrassy()->getSurface(), nullptr, board, realPlayer->getBrassy()->getRect());
    SDL_BlitSurface(virtualPlayer->getGates()->getSurface(), nullptr, board, virtualPlayer->getGates()->getRect());
    SDL_BlitSurface(realPlayer->getGates()->getSurface(), nullptr, board, realPlayer->getGates()->getRect());

    SDL_UpdateWindowSurface(window);
    SDL_Delay(1);
}

/* implementation of method for closing of Board */
void Board::closeBoard()
{
    SDL_Quit();
}

/* implementation of function which allows return width of Board */
const int Board::getBoardWidth()
{
    return this->boardWidth;
}

/* implementation of function which allows return height of Board */
const int Board::getBoardHeight()
{
    return this->boardHeight;
}
