//
//  Game.cpp
//  ChineseChess
//
//  Created by Ying Wang on 17/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#include "Game.hpp"

bool Game::quitGame = false;

Game::Game()
{
    Game::quitGame = false;
}

Game::~Game()
{
}

void Game::Init()
{
    int ret;
    ret = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO);
    assert(ret >= 0);
    window = SDL_CreateWindow("Chinese Chess", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    assert(window != NULL);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    assert(renderer != NULL);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    int imgFlags = IMG_INIT_PNG;
    ret = IMG_Init(imgFlags) & imgFlags;
    assert(ret);
    ret = TTF_Init();
    assert(ret != -1);
}

void Game::LoadTextures()
{
    backgroundTexture = new Texture(renderer, "Resources","backGround.png");
    pieceTexture.push_back(new PieceTexture(renderer, "Resources", "bjiang.png"));
    pieceTexture.push_back(new PieceTexture(renderer, "Resources", "rshuai.png"));
    pieceTexture.push_back(new PieceTexture(renderer, "Resources", "bshi.png"));
    pieceTexture.push_back(new PieceTexture(renderer, "Resources", "rshi.png"));
    pieceTexture.push_back(new PieceTexture(renderer, "Resources", "bxiang.png"));
    pieceTexture.push_back(new PieceTexture(renderer, "Resources", "rxiang.png"));
    pieceTexture.push_back(new PieceTexture(renderer, "Resources", "bma.png"));
    pieceTexture.push_back(new PieceTexture(renderer, "Resources", "rma.png"));
    pieceTexture.push_back(new PieceTexture(renderer, "Resources", "bche.png"));
    pieceTexture.push_back(new PieceTexture(renderer, "Resources", "rche.png"));
    pieceTexture.push_back(new PieceTexture(renderer, "Resources", "bpao.png"));
    pieceTexture.push_back(new PieceTexture(renderer, "Resources", "rpao.png"));
    pieceTexture.push_back(new PieceTexture(renderer, "Resources", "bzu.png"));
    pieceTexture.push_back(new PieceTexture(renderer, "Resources", "rbing.png"));
}

void Game::RenderTextures()
{
    backgroundTexture->Draw();
    
    int pieceWidth = PieceTexture::GetTotalWidth();
    int pieceHeight = PieceTexture::GetTotalHeight();
    for (int row = 0; row < numOfRow; row++)
    {
        for (int col = 0; col < numOfCol; col++ )
        {
            if ((pieces[row][col] == NULL) || (pieces[row][col]->GetCharacter() == Piece::NONE))
            {
                continue;
            }
            pieceTexture[pieces[row][col]->GetCharacter()]->Draw(Config::X_OFFSET + pieceWidth * col, Config::Y_OFFSET + pieceHeight * row);
        }
    }
}

void Game::LoadLevel()
{
    level = new Level();

    numOfRow = level->GetNumOfRow();
    numOfCol = level->GetNumOfCol();
    
    for (int row = 0; row < numOfRow; row++)
    {
        std::vector<Piece*> v;
        for (int col = 0; col < numOfCol; col++ )
        {
            Piece* p = new Piece(static_cast<int>(level->GetMap()[row * numOfCol + col]));
            p->SetRow(row);
            p->SetCol(col);
            v.push_back(p);
        }
        pieces.push_back(v);
    }
}

void Game::Close()
{
    
    for (int row = 0; row < numOfRow; row++)
    {
        for (int col = 0; col < numOfCol; col++)
        {
            delete pieces[row][col];
            pieces[row][col] = nullptr;
        }
    }
    
    for (int i = 0; i < pieceTexture.size(); i++)
    {
        delete pieceTexture[i];
        pieceTexture[i] = nullptr;
    }
    
    delete  backgroundTexture;
    backgroundTexture = nullptr;
    
    delete level;
    delete event;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    level = nullptr;
    event = nullptr;
    window = nullptr;
    renderer = nullptr;
    
    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Game::Input()
{
    int xPos, yPos;
    switch (event->type)
    {
        case SDL_QUIT:
            quitGame = true;
            break;
        case SDL_MOUSEBUTTONDOWN:
            SDL_GetMouseState(&xPos, &yPos);
            break;
        case SDL_MOUSEBUTTONUP:
            SDL_GetMouseState(&xPos, &yPos);
            break;
        default:
            break;
    }
}

void Game::MainLoop()
{
    Init();
    event = new SDL_Event();
    LoadLevel();
    LoadTextures();
    while(!quitGame)
    {
        while(SDL_PollEvent(event) != 0)
        {
            SDL_RenderClear(renderer);
            Input();
            RenderTextures();
            SDL_RenderPresent(renderer);
        }
    }
    Close();

}