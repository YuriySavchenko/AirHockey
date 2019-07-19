//
//  main.cpp
//  Air Hockey
//
//  Created by YuriySavchenko on 7/12/19.
//  Copyright © 2019 YuriySavchenko. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../headers/board.h"

void initSDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "[!] Error of SDL initialization! Error { " << SDL_GetError() << " }" << std::endl;
    }
    
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cout << "[!] Error of IMG initialization! Error { " << IMG_GetError() << " }" << std::endl;
    }
    
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2098) < 0) {
        std::cout << "[!] Error of Mixer initialization! Error { " << Mix_GetError() << " }" << std::endl;
    }
    
    if (TTF_Init() < 0) {
        std::cout << "[!] Error of TTF initialization! Error { " << TTF_GetError() << " }" << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    initSDL();
    
    std::unique_ptr<Board> board { new Board() };
    board->initBoard();
    board->updateBoard();
    
    Mix_Quit();
    TTF_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;
}
