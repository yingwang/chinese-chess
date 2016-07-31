//
//  Horse.cpp
//  ChineseChess
//
//  Created by Ying Wang on 20/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#include "Horse.hpp"
#include "PieceFactory.hpp"

std::unordered_map<int, bool> Horse::PossibleMoves(std::vector< std::vector<Piece*> >& pieces)
{
    _pieces = pieces;
    std::unordered_map<int, bool> pm;
    if (ValidMove(_row - 2, _col - 1))
    {
        pm[(_row - 2) * 10 + _col - 1] = true;
    }
    if (ValidMove(_row + 2, _col - 1))
    {
        pm[(_row + 2) * 10 + _col - 1] = true;
    }
    if (ValidMove(_row - 2, _col + 1))
    {
        pm[(_row - 2) * 10 + _col + 1] = true;
    }
    if (ValidMove(_row + 2, _col + 1))
    {
        pm[(_row + 2)* 10 + _col + 1] = true;
    }
    
    if (ValidMove(_row - 1, _col - 2))
    {
        pm[(_row - 1) * 10 + _col - 2] = true;
    }
    if (ValidMove(_row + 1, _col - 2))
    {
        pm[(_row + 1) * 10 + _col - 2] = true;
    }
    if (ValidMove(_row - 1, _col + 2))
    {
        pm[(_row - 1) * 10 + _col + 2] = true;
    }
    if (ValidMove(_row + 1, _col + 2))
    {
        pm[(_row + 1)* 10 + _col + 2] = true;
    }
    
    return pm;
}

std::vector<int> Horse::PossibleMovesAsVector(std::vector< std::vector<Piece*> >& pieces)
{
    _pieces = pieces;
    std::vector<int> pm;
    if (ValidMove(_row - 2, _col - 1))
    {
        pm.push_back((_row - 2) * 10 + _col - 1);
    }
    if (ValidMove(_row + 2, _col - 1))
    {
        pm.push_back((_row + 2) * 10 + _col - 1);
    }
    if (ValidMove(_row - 2, _col + 1))
    {
        pm.push_back((_row - 2) * 10 + _col + 1);
    }
    if (ValidMove(_row + 2, _col + 1))
    {
        pm.push_back((_row + 2)* 10 + _col + 1);
    }
    
    if (ValidMove(_row - 1, _col - 2))
    {
        pm.push_back((_row - 1) * 10 + _col - 2);
    }
    if (ValidMove(_row + 1, _col - 2))
    {
        pm.push_back((_row + 1) * 10 + _col - 2);
    }
    if (ValidMove(_row - 1, _col + 2))
    {
        pm.push_back((_row - 1) * 10 + _col + 2);
    }
    if (ValidMove(_row + 1, _col + 2))
    {
        pm.push_back((_row + 1)* 10 + _col + 2);
    }
    
    return pm;
}

bool Horse::ValidMove(int row, int col)
{
    if (!Piece::ValidMove(row, col)) return false;
    if (_pieces[_row][_col]->GetColor() == _pieces[row][col]->GetColor()) return false;
    if (abs(_row - row) == 2)
    {
        if (_pieces[(row + _row) / 2][_col]->GetCharacter() != PieceFactory::NONE) return false;
    }
    else if (abs(_col - col) == 2)
    {
        if (_pieces[_row][(col + _col) / 2]->GetCharacter() != PieceFactory::NONE) return false;
    }
    
    
    return true;
}