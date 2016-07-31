//
//  AI.cpp
//  ChineseChess
//
//  Created by Ying Wang on 31/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#include "AI.hpp"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

AI::AI(std::vector< std::vector<Piece*> >& pieces, int player)
{
    _numOfRow = Config::NUM_OF_ROW;
    _numOfCol = Config::NUM_OF_COL;
    _pieces = pieces;
    _currentPlayer = player;
    SearchForBestMove();
}

void AI::SearchForBestMove()
{
    std::vector<int> possibleMoves;
    _bestValue = INT_MIN;

    for (int row = 0; row < _numOfRow; row++)
    {
        for (int col = 0; col < _numOfCol; col++ )
        {
            if (_pieces[row][col]->GetColor() == _currentPlayer)
            {
                Move move;
                move.SetFromRow(row);
                move.SetFromCol(col);
                move.SetFromPiece(_pieces[move.GetFromRow()][move.GetFromCol()]);
                possibleMoves = _pieces[row][col]->PossibleMovesAsVector(_pieces);
                for (int i = 0; i < possibleMoves.size(); i++)
                {
                    move.SetToRow(possibleMoves[i] / 10);
                    move.SetToCol(possibleMoves[i] % 10);
                    move.SetToPiece(_pieces[move.GetToRow()][move.GetToCol()]);
                    int v = EvaluateMove(move);
                    if ( v > _bestValue)
                    {
                        _bestValue = v;
                        _bestMove.SetFromRow(row);
                        _bestMove.SetFromCol(col);
                        _bestMove.SetFromPiece(_pieces[_bestMove.GetFromRow()][_bestMove.GetFromCol()]);
                        _bestMove.SetToRow(possibleMoves[i] / 10);
                        _bestMove.SetToCol(possibleMoves[i] % 10);
                        _bestMove.SetToPiece(_pieces[_bestMove.GetToRow()][_bestMove.GetToCol()]);
                    }
                }
            }
        }
    }
}

int AI::EvaluateMove(Move move)
{
    PerformMove(move);
    int value = EvaluateState();
    RevertMove(move);
    return value;
}

int AI::EvaluateState()
{
    int value = 0;
    for (int row = 0; row < _numOfRow; row++)
    {
        for (int col = 0; col < _numOfCol; col++ )
        {
            if (_pieces[row][col]->GetColor() == _currentPlayer)
            {
                value += _pieces[row][col]->GetCharacter();
            }
            else if (_pieces[row][col]->GetColor() == (1 - _currentPlayer))
            {
                value -= _pieces[row][col]->GetCharacter();
            }
        }
    }
    return value;
}

void AI::PerformMove(Move move)
{
    _pieces[move.GetFromRow()][move.GetFromCol()] = PieceFactory::createPiece(Piece::NONE);
    _pieces[move.GetFromRow()][move.GetFromCol()]->SetRow(move.GetFromRow());
    _pieces[move.GetFromRow()][move.GetFromCol()]->SetCol(move.GetFromCol());
    _pieces[move.GetToRow()][move.GetToCol()]= move.GetFromPiece();
    _pieces[move.GetToRow()][move.GetToCol()]->SetRow(move.GetToRow());
    _pieces[move.GetToRow()][move.GetToCol()]->SetCol(move.GetToCol());
}

void AI::RevertMove(Move move)
{
    _pieces[move.GetFromRow()][move.GetFromCol()] = move.GetFromPiece();
    _pieces[move.GetFromRow()][move.GetFromCol()]->SetRow(move.GetFromRow());
    _pieces[move.GetFromRow()][move.GetFromCol()]->SetCol(move.GetFromCol());
    _pieces[move.GetToRow()][move.GetToCol()]= move.GetToPiece();
    _pieces[move.GetToRow()][move.GetToCol()]->SetRow(move.GetToRow());
    _pieces[move.GetToRow()][move.GetToCol()]->SetCol(move.GetToCol());
}

Move AI::BestMove()
{
    return _bestMove;
}