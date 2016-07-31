//
//  Cannon.cpp
//  ChineseChess
//
//  Created by Ying Wang on 20/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#include "Cannon.hpp"
#include "PieceFactory.hpp"

std::unordered_map<int, bool> Cannon::PossibleMoves(std::vector< std::vector<Piece*> >& pieces)
{
    _pieces = pieces;
    std::unordered_map<int, bool> pm;
    
    for (int i = 0 - Config::NUM_OF_ROW; i < Config::NUM_OF_ROW; i++)
    {
        if (ValidMove(_row + i, _col))
        {
            pm[(_row + i) * 10 + _col] = true;
        }
    }
    
    for (int i = 0 - Config::NUM_OF_COL; i < Config::NUM_OF_COL; i++)
    {
        if (ValidMove(_row, _col + i))
        {
            pm[_row * 10 + _col + i] = true;
        }
    }
    
    return pm;
}

std::vector<int> Cannon::PossibleMovesAsVector(std::vector< std::vector<Piece*> >& pieces)
{
    _pieces = pieces;
    std::vector<int> pm;
    
    for (int i = 0 - Config::NUM_OF_ROW; i < Config::NUM_OF_ROW; i++)
    {
        if (ValidMove(_row + i, _col))
        {
            pm.push_back((_row + i) * 10 + _col);
        }
    }
    
    for (int i = 0 - Config::NUM_OF_COL; i < Config::NUM_OF_COL; i++)
    {
        if (ValidMove(_row, _col + i))
        {
            pm.push_back(_row * 10 + _col + i);
        }
    }
    
    return pm;

}

bool Cannon::ValidMove(int row, int col)
{
    if (!Piece::ValidMove(row, col)) return false;
    
    if (_pieces[_row][_col]->GetColor() == _pieces[row][col]->GetColor()) return false;
    
    int count = 0;
    
    if ((_row - row) != 0)
    {
        int a = std::min(_row, row);
        int b = std::max(_row, row);
        for (int i = a + 1; i < b; i++)
        {
            if (_pieces[i][col]->GetCharacter() != PieceFactory::NONE)
            {
                count++;
            }
        }
    }
    else if ((_col - col) != 0)
    {
        int a = std::min(_col, col);
        int b = std::max(_col, col);
        for (int i = a + 1; i < b; i++)
        {
            if (_pieces[row][i]->GetCharacter() != PieceFactory::NONE)
            {
                count++;
            }
        }
    }
    
    if ((count == 1) && (_pieces[row][col]->GetCharacter() != PieceFactory::NONE)) return true;
    if ((count == 0) && (_pieces[row][col]->GetCharacter() == PieceFactory::NONE)) return true;
    return false;
}