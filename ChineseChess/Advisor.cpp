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

    return CheckGeneralMeet();
}

bool Advisor::CheckGeneralMeet()
{
    int brow = -1, bcol = -1, rrow = -1, rcol = -1;
    bool find = false;
    for (int i = 0; i <= 2; i++)
    {
        if (find) break;
        for (int j = 3; j <= 5; j++)
        {
            if (_pieces[i][j]->GetCharacter() == Piece::GENERAL_BLUE)
            {
                brow = i;
                bcol = j;
                break;
            }
        }
    }
    find = false;
    for (int i = 7; i <= 9; i++)
    {
        if (find) break;
        for (int j = 3; j <= 5; j++)
        {
            if (_pieces[i][j]->GetCharacter() == Piece::GENERAL_RED)
            {
                rrow = i;
                rcol = j;
                break;
            }
        }
    }
    
    if (rcol != bcol) return true; // OK
    
    // They are on the same column, check if there is any piece in between
    for (int i = brow + 1;  i < rrow; i++)
    {
        if (_pieces[i][rcol] != _pieces[_row][_col]) return true;
        
    }
    return false;
}
