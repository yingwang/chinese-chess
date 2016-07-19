//
//  Piece.cpp
//  ChineseChess
//
//  Created by Ying Wang on 19/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#include "Piece.hpp"

Piece::Piece(Piece::PieceCharacter c)
{
    character = c;
}

Piece::Piece(int c)
{
    character = c;
}

int Piece::GetCharacter()
{
    return character;
}

int Piece::GetColor()
{
    return color;
}

int Piece::GetRow()
{
    return row;
}

int Piece::GetCol()
{
    return col;
}

void Piece::SetRow(int r)
{
    row = r;
}

void Piece::SetCol(int c)
{
    col = c;
}

void Piece::SetCharacter(int c)
{
    character = c;
}