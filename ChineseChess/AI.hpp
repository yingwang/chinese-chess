//
//  AI.hpp
//  ChineseChess
//
//  Created by Ying Wang on 31/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#ifndef AI_hpp
#define AI_hpp

#include <iostream>
#include "PieceFactory.hpp"
#include "Piece.hpp"
#include "Game.hpp"
#include "Move.hpp"
#include "Header.h"

class AI
{
private:
    Move _bestMove;
    int _bestValue;
    int _numOfRow;
    int _numOfCol;
    std::vector< std::vector<Piece*> > _pieces;
    int _currentPlayer;
    
public:
    int PieceCharacterValue[15] =
    {
        1000,//GENERAL_BLUE,
        1000,//GENERAL_RED,
        100,//ADVISOR_BLUE,
        100,//ADVISOR_RED,
        80,//ELEPHANT_BLUE,
        80,//ELEPHANT_RED,
        150,//HORSE_BLUE,
        150,//HORSE_RED,
        300,//CHARIOT_BLUE,
        300,//CHARIOT_RED,
        180,//CANNON_BLUE,
        180,//CANNON_RED,
        80,//SOLDIER_BLUE,
        80,//SOLDIER_RED,
        0,//NONE,
    };

    AI(std::vector< std::vector<Piece*> >& pieces, int player);
    void SearchForBestMove();
    int EvaluateMove(Move move);
    int EvaluateState();
    void PerformMove(Move move);
    void RevertMove(Move move);
    Move BestMove();
};

#endif /* AI_hpp */
