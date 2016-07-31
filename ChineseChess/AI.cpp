//
//  AI.cpp
//  ChineseChess
//
//  Created by Ying Wang on 31/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#include "AI.hpp"

AI::AI(std::vector< std::vector<Piece*> >& pieces, int player)
{
    bestMove.SetFromRow(0);
    bestMove.SetFromCol(0);
    bestMove.SetToRow(1);
    bestMove.SetToCol(0);
    bestMove.SetFromPiece(pieces[bestMove.GetFromRow()][bestMove.GetFromCol()]);
    bestMove.SetToPiece(pieces[bestMove.GetToRow()][bestMove.GetToCol()]);
}

Move AI::BestMove()
{
    return bestMove;
}