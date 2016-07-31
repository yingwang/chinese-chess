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
    _numOfRow = Config::NUM_OF_ROW;
    _numOfCol = Config::NUM_OF_COL;
    _pieces = pieces;
    _currentPlayer = player;
    SearchForBestMove();
//    bestMove.SetFromRow(0);
//    bestMove.SetFromCol(0);
//    bestMove.SetToRow(1);
//    bestMove.SetToCol(0);
//    bestMove.SetFromPiece(pieces[bestMove.GetFromRow()][bestMove.GetFromCol()]);
//    bestMove.SetToPiece(pieces[bestMove.GetToRow()][bestMove.GetToCol()]);
}

void AI::SearchForBestMove()
{
    std::vector<int> possibleMoves;
    for (int row = 0; row < _numOfRow; row++)
    {
        for (int col = 0; col < _numOfCol; col++ )
        {
            if (_pieces[row][col]->GetColor() == _currentPlayer)
            {
                possibleMoves = _pieces[row][col]->PossibleMovesAsVector(_pieces);
                for (int i = 0; i < possibleMoves.size(); i++)
                {
                    if (_bestMove.GetFromRow() != -1) return;
                    _bestMove.SetFromRow(row);
                    _bestMove.SetFromCol(col);
                    _bestMove.SetToRow(possibleMoves[i] / 10);
                    _bestMove.SetToCol(possibleMoves[i] % 10);
                    _bestMove.SetFromPiece(_pieces[_bestMove.GetFromRow()][_bestMove.GetFromCol()]);
                    _bestMove.SetToPiece(_pieces[_bestMove.GetToRow()][_bestMove.GetToCol()]);
                }
            }
        }
    }
}

Move AI::BestMove()
{
    return _bestMove;
}