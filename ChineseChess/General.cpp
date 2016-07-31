//
//  General.cpp
//  ChineseChess
//
//  Created by Ying Wang on 20/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#include "General.hpp"
#include "PieceFactory.hpp"

std::vector<int> General::PossibleMovesAsVector(std::vector< std::vector<Piece*> >& pieces)
{
    _pieces = pieces;
    _possibleMovesAsVector.clear();
    if (ValidMove(_row - 1, _col))
    {
        _possibleMovesAsVector.push_back((_row - 1) * 10 + _col);
    }
    if (ValidMove(_row + 1, _col))
    {
        _possibleMovesAsVector.push_back((_row + 1) * 10 + _col);
    }
    if (ValidMove(_row, _col - 1))
    {
        _possibleMovesAsVector.push_back(_row * 10 + _col - 1);
    }
    if (ValidMove(_row, _col + 1))
    {
        _possibleMovesAsVector.push_back(_row * 10 + _col + 1);
    }
    return _possibleMovesAsVector;
}


bool General::ValidMove(int row, int col)
{
    if (!Piece::ValidMove(row, col)) return false;
    if (_pieces[_row][_col]->GetColor() == _pieces[row][col]->GetColor()) return false;
    if ((col < 3) || (col > 5)) return false;
    // BLUE
    if (GetColor() == 0)
    {
        if (row > 2) return false;
        // General can not facing each other directly
        if (col != _col)
        {
            for (int i = (row + 1); i < Config::NUM_OF_ROW; i++)
            {
                if (_pieces[i][col]->GetCharacter() == Piece::GENERAL_RED) return false;
                if (_pieces[i][col]->GetColor() != -1) break;
            }
        }
    }
    // RED
    if (GetColor() == 1)
    {
        if (row < 7) return false;
        if (col != _col)
        {
            for (int i = (row - 1); i >= 0; i--)
            {
                if (_pieces[i][col]->GetCharacter() == Piece::GENERAL_BLUE) return false;
                if (_pieces[i][col]->GetColor() != -1) break;
            }
        }
    }
    
    return true;
}