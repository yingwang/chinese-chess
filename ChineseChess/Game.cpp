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
}

void Game::RenderTextures()
{
    backgroundTexture->Draw();
}

void Game::Close()
{
    delete  backgroundTexture;
    backgroundTexture = NULL;
    
    delete event;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    event = NULL;
    window = NULL;
    renderer = NULL;
    
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