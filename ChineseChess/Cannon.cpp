//
//  Cannon.cpp
//  ChineseChess
//
//  Created by Ying Wang on 20/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#include "Cannon.hpp"
#include "PieceFactory.hpp"

std::vector<int> Cannon::PossibleMovesAsVector(std::vector< std::vector<Piece*> >& pieces)
{
    _pieces = pieces;
    _possibleMovesAsVector.clear();
    for (int i = 0 - Config::NUM_OF_ROW; i < Config::NUM_OF_ROW; i++)
    {
        if (ValidMove(_row + i, _col))
        {
            _possibleMovesAsVector.push_back((_row + i) * 10 + _col);
        }
    }
    
    for (int i = 0 - Config::NUM_OF_COL; i < Config::NUM_OF_COL; i++)
    {
        if (ValidMove(_row, _col + i))
        {
            _possibleMovesAsVector.push_back(_row * 10 + _col + i);
        }
    }
    
    return _possibleMovesAsVector;

}

bool Cannon::ValidMove(int row, int col)
{
    if (!Piece::ValidMove(row, col)) return false;
    
    if (_pieces[_row][_col]->GetColor() == _pieces[row][col]->GetColor()) return false;
    
    int count = 0;
    
    if (row != _row)
    {
        int a = std::min(_row, row);
        int b = std::max(_row, row);
        for (int i = a + 1; i < b; i++)
        {
            if (_pieces[i][col]->GetCharacter() != Piece::NONE)
            {
                count++;
            }
        }
    }
    else if (col != _col)
    {
        int a = std::min(_col, col);
        int b = std::max(_col, col);
        for (int i = a + 1; i < b; i++)
        {
            if (_pieces[row][i]->GetCharacter() != Piece::NONE)
            {
                count++;
            }
        }
    }
    
    if ((count == 1) && (_pieces[row][col]->GetCharacter() != Piece::NONE)) return true;
    if ((count == 0) && (_pieces[row][col]->GetCharacter() == Piece::NONE)) return true;
    return false;
}