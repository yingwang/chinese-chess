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
    winner = -1;
    modeAI = 0; // AI play Blue
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
    textTexture.push_back(new TextTexture(renderer, "Resources", "FreeMonoBold.ttf", "RED"));
}

void Game::RenderTextures()
{
    backgroundTexture->Draw();
    
    string status;
    switch (currentGameState)
    {
        case GameState::BLUE_TURN:
            status = "BLUE";
            break;
        case GameState::RED_TURN:
            status = "RED";
            break;
        case GameState::END:
            status = "END";
            break;
        default:
            break;
    }
    textTexture[0]->Update(status.c_str(), currentGameState);
    
    for (int i = 0; i < textTexture.size(); i++)
    {
        textTexture[i]->Draw(Config::TEXT_X_OFFSET, Config::TEXT_Y_OFFSET + Config::TEXT_Y_GAP * i);
    }
    
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
            int c = static_cast<int>(level->GetMap()[row * numOfCol + col]);
            Piece* p = PieceFactory::createPiece(static_cast<Piece::PieceCharacter>(c));
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
    
    for (int i = 0; i < textTexture.size(); i++)
    {
        delete textTexture[i];
        textTexture[i] = nullptr;
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
        if (pieces[currentMove.GetFromRow()][currentMove.GetFromCol()]->GetCharacter() == Piece::NONE)
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
    GameState state = currentGameState;
    currentMove.SetToLocation(xPos, yPos);
    
    if (currentMove.GetValidMove())
    {
        currentMove.SetFromPiece(pieces[currentMove.GetFromRow()][currentMove.GetFromCol()]);
        currentMove.SetToPiece(pieces[currentMove.GetToRow()][currentMove.GetToCol()]);
        if (currentMove.GetFromPiece()->GetCharacter() != Piece::PieceCharacter::NONE)
        {
            if ((currentMove.GetFromPiece()->PossibleMoves(pieces)[currentMove.GetToRow() * 10 + currentMove.GetToCol()] == true) && (currentMove.GetFromPiece()->GetColor() != currentMove.GetToPiece()->GetColor()))
            {
                PerformMove(currentMove);
                if (currentGameState == GameState::RED_TURN)
                {
                    if (currentMove.GetToPiece()->GetCharacter() == Piece::GENERAL_BLUE)
                    {
                        currentGameState = GameState::END;
                        winner = 0;
                    }
                    else
                    {
                        currentGameState = GameState::BLUE_TURN;
                    }
                }
                else
                {
                    if (currentMove.GetToPiece()->GetCharacter() == Piece::GENERAL_RED)
                    {
                        currentGameState = GameState::END;
                        winner = 1;
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
        if (state != currentGameState) TriggerAIEvent();
    }
}

void Game::PerformMove(Move& move)
{
    pieces[move.GetFromRow()][move.GetFromCol()] = PieceFactory::createPiece(Piece::PieceCharacter::NONE);
    pieces[move.GetFromRow()][move.GetFromCol()]->SetRow(move.GetFromRow());
    pieces[move.GetFromRow()][move.GetFromCol()]->SetCol(move.GetFromCol());
    pieces[move.GetToRow()][move.GetToCol()]= move.GetFromPiece();
    pieces[move.GetToRow()][move.GetToCol()]->SetRow(move.GetToRow());
    pieces[move.GetToRow()][move.GetToCol()]->SetCol(move.GetToCol());
}

void Game::Input(bool isAI)
{
    int xPos, yPos;
    switch (event->type)
    {
        case SDL_QUIT:
            quitGame = true;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (isAI) break;
            if (currentGameState != GameState::END)
            {
                SDL_GetMouseState(&xPos, &yPos);
                OnMouseButtonDown(xPos, yPos);
            }
            break;
        case SDL_MOUSEBUTTONUP:
            if (isAI) break;
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

void Game::AIPlay()
{
    currentMove = AI(pieces, modeAI).BestMove();
    PerformMove(currentMove);
    
    if (currentGameState == GameState::RED_TURN)
    {
        if (currentMove.GetToPiece()->GetCharacter() == Piece::GENERAL_BLUE)
        {
            currentGameState = GameState::END;
            winner = 1;
        }
        else
        {
            currentGameState = GameState::BLUE_TURN;
        }
    }
    else
    {
        if (currentMove.GetToPiece()->GetCharacter() == Piece::GENERAL_RED)
        {
            currentGameState = GameState::END;
            winner = 0;
        }
        else
        {
            currentGameState = GameState::RED_TURN;
        }
    }

    currentMove.ResetMove();
    currentMove.ResetValidMove();
}

void Game::TriggerAIEvent()
{
    Uint32 gameStateChanged = SDL_RegisterEvents(1);
    if (gameStateChanged != ((Uint32)-1)) {
        SDL_Event event;
        SDL_memset(&event, 0, sizeof(event));
        event.type = gameStateChanged;
        SDL_PushEvent(&event);
    }
}

void Game::Update()
{
    switch (currentGameState)
    {
        case GameState::RED_TURN:
            if (modeAI != 1)
            {
                Input(false);
            }
            else
            {
                Input(true);
                AIPlay();
            }
            break;
        case GameState::BLUE_TURN:
            if (modeAI != 0)
            {
                Input(false);
            }
            else
            {
                Input(true);
                AIPlay();
            }
            break;
        case GameState::END:
            Input(false);
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
            Update();
            RenderTextures();
            SDL_RenderPresent(renderer);
        }
    }
    Close();

}