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
    
    SearchForBestMove(0);
}

void AI::SearchForBestMove(int depth)
{
    std::vector<int> possibleMoves;
    int maxValue = INT_MIN;
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
                    
                    PerformMove(move);
                    
                    int value = SearchForBestMoveRecur(depth + 1); //EvaluateState(0);//only search current step
                    
                    RevertMove(move);
                    
                    if (value > maxValue)
                    {
                        maxValue = value;
                        ///std::cout << "** maxValue: " << maxValue << std::endl;
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
    std::cout << "**** maxValue: " << maxValue << std::endl;
}

int AI::SearchForBestMoveRecur(int depth)
{
    std::vector<int> possibleMoves;
    int minValue = INT_MAX;
    int maxValue = INT_MIN;
    int player = (_currentPlayer + depth) % 2;
    for (int row = 0; row < _numOfRow; row++)
    {
        for (int col = 0; col < _numOfCol; col++ )
        {
            if (_pieces[row][col]->GetColor() == player)
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
                    
                    PerformMove(move);
                    int value;
                    if (depth < (SEARCH_DEPTH - 1))
                    {
                        value = SearchForBestMoveRecur(depth + 1);
                    }
                    else if (depth == (SEARCH_DEPTH - 1))
                    {
                        value = EvaluateState(depth);
                    }
                    
                    if (depth % 2 == 0)
                    {
                        if (value > maxValue)
                        {
                            maxValue = value;
                            //std::cout << "maxValue: " << maxValue << std::endl;
                        }
                    }
                    else
                    {
                        if (value < minValue)
                        {
                            minValue = value;
                            //std::cout << "minValue: " << minValue << std::endl;
                        }
                    }
                    RevertMove(move);
                }
            }
        }
    }
    if (depth % 2 == 0)
    {
        //std::cout << "** maxValue: " << maxValue << std::endl;
        return maxValue;
    }
    else
    {
        //std::cout << "** minValue: " << minValue << std::endl;
        return minValue;
    }
}

int AI::GetPositionValue(int color, int row, int col)
{
    int pos_value = 0;
    // blue
    if (color == 0)
    {
        if (row >= 7)
        {
            pos_value += 20;
        }
        if (row > 4)
        {
            pos_value += 10;
        }
    }
    else // red
    {
        if (row <= 2)
        {
            pos_value += 20;
        }
        if (row < 5)
        {
            pos_value += 10;
        }
    }
    if ((col > 2) && (col < 6))
    {
        pos_value += 10;
    }
    return pos_value;
}

int AI::EvaluateState(int depth)
{
    int value = 0;
    int player = _currentPlayer; //(_currentPlayer + depth) % 2;
    
    for (int row = 0; row < _numOfRow; row++)
    {
        for (int col = 0; col < _numOfCol; col++ )
        {
            if (_pieces[row][col]->GetColor() == player)
            {
                value = value + PieceCharacterValue[_pieces[row][col]->GetCharacter()] + GetPositionValue(player, row, col);
            }
            else if (_pieces[row][col]->GetColor() == (1 - player))
            {
                value = value - PieceCharacterValue[_pieces[row][col]->GetCharacter()] - GetPositionValue((1-player), row, col);
            }
        }
    }
    return value;
}

void AI::PerformMove(Move& move)
{
    _pieces[move.GetToRow()][move.GetToCol()]= move.GetFromPiece();
    _pieces[move.GetToRow()][move.GetToCol()]->SetRow(move.GetToRow());
    _pieces[move.GetToRow()][move.GetToCol()]->SetCol(move.GetToCol());
    _pieces[move.GetFromRow()][move.GetFromCol()] = PieceFactory::createPiece(Piece::NONE);
    _pieces[move.GetFromRow()][move.GetFromCol()]->SetRow(move.GetFromRow());
    _pieces[move.GetFromRow()][move.GetFromCol()]->SetCol(move.GetFromCol());
}

void AI::RevertMove(Move& move)
{
    Piece* from = _pieces[move.GetFromRow()][move.GetFromCol()];
    _pieces[move.GetFromRow()][move.GetFromCol()] = move.GetFromPiece();
    _pieces[move.GetFromRow()][move.GetFromCol()]->SetRow(move.GetFromRow());
    _pieces[move.GetFromRow()][move.GetFromCol()]->SetCol(move.GetFromCol());
    _pieces[move.GetToRow()][move.GetToCol()]= move.GetToPiece();
    _pieces[move.GetToRow()][move.GetToCol()]->SetRow(move.GetToRow());
    _pieces[move.GetToRow()][move.GetToCol()]->SetCol(move.GetToCol());
    delete from;
    from = nullptr;
}

Move AI::BestMove()
{
    return _bestMove;
}