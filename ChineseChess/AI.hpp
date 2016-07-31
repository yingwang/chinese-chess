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

class AI
{
private:
    Move bestMove;
public:
    AI(std::vector< std::vector<Piece*> >& pieces, int player);
    Move BestMove();
};

#endif /* AI_hpp */
