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
    AI(std::vector< std::vector<Piece*> >& pieces, int player);
    void SearchForBestMove();
    int EvaluateMove(Move move);
    int EvaluateState();
    void PerformMove(Move move);
    void RevertMove(Move move);
    Move BestMove();
};

#endif /* AI_hpp */
