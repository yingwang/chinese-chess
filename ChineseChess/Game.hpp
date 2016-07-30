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
#include <vector>
#include "Header.h"
#include "Config.h"
#include "Texture.hpp"
#include "PieceTexture.hpp"
#include "Piece.hpp"
#include "Level.hpp"
#include "Move.hpp"

class Game
{
private:
    int numOfRow;
    int numOfCol;
    
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event* event;

    std::vector< std::vector<Piece*> > pieces;
    Level* level;
    Move currentMove;
    
    Texture* backgroundTexture;
    std::vector<PieceTexture*> pieceTexture;
    
    void Init();
    void LoadTextures();
    void RenderTextures();
    void Close();
    void Input();
    void LoadLevel();
    void OnMouseButtonDown(int xPos, int yPos);
    void OnMouseButtonUp(int xPos, int yPos);
    void PerformMove();

public:
    Game();
    ~Game();
    static bool quitGame;
    void MainLoop();
};

#endif /* Game_hpp */
