//
//  Elephant.cpp
//  ChineseChess
//
//  Created by Ying Wang on 20/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#include "Elephant.hpp"
#include "Game.hpp"
#include "PieceFactory.hpp"

std::unordered_map<int, bool> Elephant::PossibleMoves(std::vector< std::vector<Piece*> >& pieces)
{
    _pieces = pieces;
    std::unordered_map<int, bool> pm;
    if (ValidMove(_row - 2, _col - 2))
    {
        pm[(_row - 2) * 10 + _col - 2] = true;
    }
    if (ValidMove(_row + 2, _col - 2))
    {
        pm[(_row + 2) * 10 + _col - 2] = true;
    }
    if (ValidMove(_row - 2, _col + 2))
    {
        pm[(_row - 2) * 10 + _col + 2] = true;
    }
    if (ValidMove(_row + 2, _col + 2))
    {
        pm[(_row + 2)* 10 + _col + 2] = true;
    }
    return pm;
}

bool Elephant::ValidMove(int row, int col)
{
    if (!Piece::ValidMove(row, col)) return false;
    
    // BLUE
    if (GetColor() == 0)
    {
        if (row > 4) return false;
    }
    // RED
    if (GetColor() == 1)
    {
        if (row < 5) return false;
    }
    
    if (_pieces[(row + _row) / 2][(col + _col) / 2]->GetCharacter() != PieceFactory::NONE) return false;
    
    return true;
}