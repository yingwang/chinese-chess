//
//  Soldier.cpp
//  ChineseChess
//
//  Created by Ying Wang on 20/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#include "Soldier.hpp"

std::vector<int> Soldier::PossibleMovesAsVector(std::vector< std::vector<Piece*> >& pieces)
{
    _pieces = pieces;
    _possibleMovesAsVector.clear();
    // BLUE
    if (GetColor() == 0)
    {
        // Before river
        if (_row <= 4)
        {
            if (ValidMove(_row + 1, _col))
            {
                _possibleMovesAsVector.push_back((_row + 1) * 10 + _col);
            }
        }
        else
        {
            if (ValidMove(_row + 1, _col))
            {
                _possibleMovesAsVector.push_back((_row + 1) * 10 + _col);
            }
            if (ValidMove(_row, _col + 1))
            {
                _possibleMovesAsVector.push_back(_row * 10 + _col + 1);
            }
            if (ValidMove(_row, _col - 1))
            {
                _possibleMovesAsVector.push_back(_row * 10 + _col - 1);
            }
        }
    }
    // RED
    if (GetColor() == 1)
    {
        // Before river
        if (_row > 4)
        {
            if (ValidMove(_row - 1, _col))
            {
                _possibleMovesAsVector.push_back((_row - 1) * 10 + _col);
            }
        }
        else
        {
            if (ValidMove(_row - 1, _col))
            {
                _possibleMovesAsVector.push_back((_row - 1) * 10 + _col);
            }
            if (ValidMove(_row, _col + 1))
            {
                _possibleMovesAsVector.push_back(_row * 10 + _col + 1);
            }
            if (ValidMove(_row, _col - 1))
            {
                _possibleMovesAsVector.push_back(_row * 10 + _col - 1);
            }
            
        }
    }
    
    return _possibleMovesAsVector;
}

bool Soldier::ValidMove(int row, int col)
{
    if (!Piece::ValidMove(row, col)) return false;
    if (_pieces[_row][_col]->GetColor() == _pieces[row][col]->GetColor()) return false;
    return true;
}