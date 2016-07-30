//
//  Chariot.cpp
//  ChineseChess
//
//  Created by Ying Wang on 20/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#include "Chariot.hpp"
#include "PieceFactory.hpp"

std::unordered_map<int, bool> Chariot::PossibleMoves(std::vector< std::vector<Piece*> >& pieces)
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

bool Chariot::ValidMove(int row, int col)
{
    if (!Piece::ValidMove(row, col)) return false;
    if ((_row - row) != 0)
    {
        int a = std::min(_row, row);
        int b = std::max(_row, row);
        for (int i = a + 1; i < b; i++)
        {
            if (_pieces[i][col]->GetCharacter() != PieceFactory::NONE) return false;
        }
    }
    else if ((_col - col) != 0)
    {
        int a = std::min(_col, col);
        int b = std::max(_col, col);
        for (int i = a + 1; i < b; i++)
        {
            if (_pieces[row][i]->GetCharacter() != PieceFactory::NONE) return false;
        }
    }
        
    return true;
}