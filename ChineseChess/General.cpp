//
//  General.cpp
//  ChineseChess
//
//  Created by Ying Wang on 20/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#include "General.hpp"

std::unordered_map<int, bool> General::PossibleMoves(std::vector< std::vector<Piece*> >& pieces)
{
    _pieces = pieces;
    std::unordered_map<int, bool> pm;
    if (ValidMove(_row - 1, _col))
    {
        pm[(_row - 1) * 10 + _col] = true;
    }
    if (ValidMove(_row + 1, _col))
    {
        pm[(_row + 1) * 10 + _col] = true;
    }
    if (ValidMove(_row, _col - 1))
    {
        pm[_row * 10 + _col - 1] = true;
    }
    if (ValidMove(_row, _col + 1))
    {
        pm[_row * 10 + _col + 1] = true;
    }
    return pm;
}

std::vector<int> General::PossibleMovesAsVector(std::vector< std::vector<Piece*> >& pieces)
{
    _pieces = pieces;
    std::vector<int> pm;
    if (ValidMove(_row - 1, _col))
    {
        pm.push_back((_row - 1) * 10 + _col);
    }
    if (ValidMove(_row + 1, _col))
    {
        pm.push_back((_row + 1) * 10 + _col);
    }
    if (ValidMove(_row, _col - 1))
    {
        pm.push_back(_row * 10 + _col - 1);
    }
    if (ValidMove(_row, _col + 1))
    {
        pm.push_back(_row * 10 + _col + 1);
    }
    return pm;
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
    }
    // RED
    if (GetColor() == 1)
    {
        if (row < 7) return false;
    }
    return true;
}