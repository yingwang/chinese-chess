//
//  Advisor.cpp
//  ChineseChess
//
//  Created by Ying Wang on 20/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#include "Advisor.hpp"
#include "PieceFactory.hpp"

std::vector<int> Advisor::PossibleMovesAsVector(std::vector< std::vector<Piece*> >& pieces)
{
    _pieces = pieces;
    _possibleMovesAsVector.clear();
    if (ValidMove(_row - 1, _col - 1))
    {
        _possibleMovesAsVector.push_back((_row - 1) * 10 + _col - 1);
    }
    if (ValidMove(_row + 1, _col - 1))
    {
        _possibleMovesAsVector.push_back((_row + 1) * 10 + _col - 1);
    }
    if (ValidMove(_row - 1, _col + 1))
    {
        _possibleMovesAsVector.push_back((_row - 1) * 10 + _col + 1);
    }
    if (ValidMove(_row + 1, _col + 1))
    {
        _possibleMovesAsVector.push_back((_row + 1)* 10 + _col + 1);
    }
    return _possibleMovesAsVector;
}

bool Advisor::ValidMove(int row, int col)
{
    if (!Piece::ValidMove(row, col)) return false;
    if (_pieces[_row][_col]->GetColor() == _pieces[row][col]->GetColor()) return false;
    if ((col < 3) || (col > 5)) return false;
    // BLUE
    if (GetColor() == 0)
    {
        if (row > 2) return false;
    }
    // RED
    if (GetColor() == 1)
    {
        if (row < 7) return false;
    }

    return true;
}
