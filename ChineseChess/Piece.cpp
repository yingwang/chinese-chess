//
//  Piece.cpp
//  ChineseChess
//
//  Created by Ying Wang on 19/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#include "Piece.hpp"

int Piece::GetCharacter()
{
    return _character;
}

int Piece::GetRow()
{
    return _row;
}

int Piece::GetCol()
{
    return _col;
}

void Piece::SetRow(int r)
{
    _row = r;
}

void Piece::SetCol(int c)
{
    _col = c;
}

void Piece::SetCharacter(int c)
{
    _character = c;
}

bool Piece::InBoard(int row, int col)
{
    if ((row >= Config::NUM_OF_ROW) || (row < 0)) return false;
    if ((col >= Config::NUM_OF_COL) || (col < 0)) return false;
    return true;
}

bool Piece::ValidMove(int row, int col)
{
    if (!InBoard(row, col)) return false;
    return true;
}