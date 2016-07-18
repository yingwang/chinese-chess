//
//  Game.hpp
//  ChineseChess
//
//  Created by Ying Wang on 17/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include "Header.h"
#include "Config.h"
#include "Texture.hpp"

class Game
{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event* event;

    Texture* backgroundTexture;
    void Init();
    void LoadTextures();
    void RenderTextures();
    void Close();
    void Input();

public:
    Game();
    ~Game();
    static bool quitGame;
    void MainLoop();
};

#endif /* Game_hpp */
