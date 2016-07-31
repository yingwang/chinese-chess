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
#include "TextTexture.hpp"
#include "AI.hpp"

class Game
{
private:
    int numOfRow;
    int numOfCol;
    int winner; // 0: BLUE; 1: RED;
    int modeAI; // 0: AI play BLUE; 1: AI play RED;
    
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event* event;

    std::vector< std::vector<Piece*> > pieces;
    Level* level;
    Move currentMove;
    
    Texture* backgroundTexture;
    std::vector<PieceTexture*> pieceTexture;
    std::vector<TextTexture*> textTexture;
    
    void Init();
    void LoadTextures();
    void RenderTextures();
    void Close();
    void Input(bool isAI);
    void AIPlay();
    void LoadLevel();
    void OnMouseButtonDown(int xPos, int yPos);
    void OnMouseButtonUp(int xPos, int yPos);
    void PerformMove(Move& move);

public:
    enum GameState {
        RED_TURN,
        BLUE_TURN,
        END,
    };
    
    Game();
    ~Game();
    static bool quitGame;
    void Update();
    void MainLoop();
    GameState currentGameState;
};

#endif /* Game_hpp */
