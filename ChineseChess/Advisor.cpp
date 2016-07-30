//
//  Advisor.cpp
//  ChineseChess
//
//  Created by Ying Wang on 20/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#include "Advisor.hpp"

std::unordered_map<int, bool> Advisor::PossibleMoves(std::vector< std::vector<Piece*> >& pieces)
{
    std::unordered_map<int, bool> pm;
    if (ValidMove(_row - 1, _col - 1))
    {
        pm[(_row - 1) * 10 + _col - 1] = true;
    }
    if (ValidMove(_row + 1, _col - 1))
    {
        pm[(_row + 1) * 10 + _col - 1] = true;
    }
    if (ValidMove(_row - 1, _col + 1))
    {
        pm[(_row - 1) * 10 + _col + 1] = true;
    }
    if (ValidMove(_row + 1, _col + 1))
    {
        pm[(_row + 1)* 10 + _col + 1] = true;
    }
    return pm;
}

bool Advisor::ValidMove(int row, int col)
{
    if (!Piece::ValidMove(row, col)) return false;
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