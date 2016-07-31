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

std::vector<int> Elephant::PossibleMovesAsVector(std::vector< std::vector<Piece*> >& pieces)
{
    _pieces = pieces;
    _possibleMovesAsVector.clear();
    if (ValidMove(_row - 2, _col - 2))
    {
        _possibleMovesAsVector.push_back((_row - 2) * 10 + _col - 2);
    }
    if (ValidMove(_row + 2, _col - 2))
    {
        _possibleMovesAsVector.push_back((_row + 2) * 10 + _col - 2);
    }
    if (ValidMove(_row - 2, _col + 2))
    {
        _possibleMovesAsVector.push_back((_row - 2) * 10 + _col + 2);
    }
    if (ValidMove(_row + 2, _col + 2))
    {
        _possibleMovesAsVector.push_back((_row + 2)* 10 + _col + 2);
    }
    return _possibleMovesAsVector;
}

bool Elephant::ValidMove(int row, int col)
{
    if (!Piece::ValidMove(row, col)) return false;
    if (_pieces[_row][_col]->GetColor() == _pieces[row][col]->GetColor()) return false;
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
    
    if (_pieces[(row + _row) / 2][(col + _col) / 2]->GetCharacter() != Piece::NONE) return false;
    
    return true;
}