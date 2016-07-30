//
//  Game.cpp
//  ChineseChess
//
//  Created by Ying Wang on 17/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#include "Game.hpp"
#include "PieceFactory.hpp"

bool Game::quitGame = false;

Game::Game()
{
    Game::quitGame = false;
    currentGameState = GameState::RED_TURN;
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
            if ((pieces[row][col] == NULL) || (pieces[row][col]->GetCharacter() == PieceFactory::NONE))
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
            int c = static_cast<int>(level->GetMap()[row * numOfCol + col]);
            Piece* p = PieceFactory::createPiece(static_cast<PieceFactory::PieceCharacter>(c));
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

void Game::OnMouseButtonDown(int xPos, int yPos)
{
    if (currentMove.GetFromRow() < 0)
    {
        currentMove.SetFromLocation(xPos, yPos);
        if (pieces[currentMove.GetFromRow()][currentMove.GetFromCol()]->GetCharacter() == PieceFactory::NONE)
        {
            currentMove.ResetMove();
            currentMove.ResetValidMove();
            return;
        }
        if (((pieces[currentMove.GetFromRow()][currentMove.GetFromCol()]->GetColor() == 0) && currentGameState != GameState::BLUE_TURN)
            || ((pieces[currentMove.GetFromRow()][currentMove.GetFromCol()]->GetColor() == 1) && currentGameState != GameState::RED_TURN))
        {
            currentMove.ResetMove();
            currentMove.ResetValidMove();
        }
    }
}

void Game::OnMouseButtonUp(int xPos, int yPos)
{
    currentMove.SetToLocation(xPos, yPos);
    
    if (currentMove.GetValidMove())
    {
        currentMove.SetFromPiece(pieces[currentMove.GetFromRow()][currentMove.GetFromCol()]);
        currentMove.SetToPiece(pieces[currentMove.GetToRow()][currentMove.GetToCol()]);
        if (currentMove.GetFromPiece()->GetCharacter() != PieceFactory::PieceCharacter::NONE)
        {
            if ((currentMove.GetFromPiece()->PossibleMoves(pieces)[currentMove.GetToRow() * 10 + currentMove.GetToCol()] == true) && (currentMove.GetFromPiece()->GetColor() != currentMove.GetToPiece()->GetColor()))
            {
                PerformMove();
                if (currentGameState == GameState::RED_TURN)
                {
                    if (currentMove.GetToPiece()->GetCharacter() == PieceFactory::GENERAL_BLUE)
                    {
                        currentGameState = GameState::END;
                    }
                    else
                    {
                        currentGameState = GameState::BLUE_TURN;
                    }
                }
                else
                {
                    if (currentMove.GetToPiece()->GetCharacter() == PieceFactory::GENERAL_RED)
                    {
                        currentGameState = GameState::END;
                    }
                    else
                    {
                        currentGameState = GameState::RED_TURN;
                    }
                }
            }
        }
        currentMove.ResetMove();
        currentMove.ResetValidMove();
    }
}

void Game::PerformMove()
{
    pieces[currentMove.GetFromRow()][currentMove.GetFromCol()] = PieceFactory::createPiece(PieceFactory::PieceCharacter::NONE);
    pieces[currentMove.GetFromRow()][currentMove.GetFromCol()]->SetRow(currentMove.GetFromRow());
    pieces[currentMove.GetFromRow()][currentMove.GetFromCol()]->SetCol(currentMove.GetFromCol());
    pieces[currentMove.GetToRow()][currentMove.GetToCol()]= currentMove.GetFromPiece();
    pieces[currentMove.GetToRow()][currentMove.GetToCol()]->SetRow(currentMove.GetToRow());
    pieces[currentMove.GetToRow()][currentMove.GetToCol()]->SetCol(currentMove.GetToCol());
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
            if (currentGameState != GameState::END)
            {
                SDL_GetMouseState(&xPos, &yPos);
                OnMouseButtonDown(xPos, yPos);
            }
            break;
        case SDL_MOUSEBUTTONUP:
            if (currentGameState != GameState::END)
            {
                SDL_GetMouseState(&xPos, &yPos);
                OnMouseButtonUp(xPos, yPos);
            }
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