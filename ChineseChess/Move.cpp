//
//  Move.cpp
//  ChineseChess
//
//  Created by Ying Wang on 19/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#include "Move.hpp"

Move::Move()
{
    ResetMove();
}

Move::~Move()
{
    fromRow = -1;
    fromCol = -1;
    toRow = -1;
    toCol = -1;
    fromPiece = NULL;
    toPiece = NULL;
    validMove = false;
}

void Move::SetFromRow(int r)
{
    fromRow = r;
}

int Move::GetFromRow()
{
    return fromRow;
}

void Move::SetFromCol(int c)
{
    fromCol = c;
}

int Move::GetFromCol()
{
    return fromCol;
}

void Move::SetToRow(int r)
{
    toRow = r;
}

int Move::GetToRow()
{
    return toRow;
}

void Move::SetToCol(int c)
{
    toCol = c;
}

int Move::GetToCol()
{
    return toCol;
}

void Move::SetFromLocation(int x, int y)
{
    fromRow = (y - Config::Y_OFFSET) / PieceTexture::GetTotalHeight();
    fromCol = (x - Config::X_OFFSET) / PieceTexture::GetTotalWidth();
}

void Move::SetToLocation(int x, int y)
{
    toRow = (y - Config::Y_OFFSET) / PieceTexture::GetTotalHeight();
    toCol = (x - Config::X_OFFSET) / PieceTexture::GetTotalWidth();
    if ((fromRow == toRow) && (fromCol == toCol))
    {
        return;
    }
    ValidateMove();
}

void Move::ValidateMove()
{
    if ((fromRow < 0)||(fromRow >= Config::NUM_OF_ROW)||(fromCol < 0)||(fromCol >= Config::NUM_OF_COL))
    {
        ResetMove();
        return;
    }
    if ((toRow < 0)||(toRow >= Config::NUM_OF_ROW)||(toCol < 0)||(toCol >= Config::NUM_OF_COL))
    {
        ResetMove();
        return;
    }
    if ((fromRow == toRow) && (fromCol == toCol))
    {
        ResetMove();
        return;
    }

    validMove = true;
}

bool Move::GetValidMove()
{
    return validMove;
}

void Move::ResetValidMove()
{
    validMove = false;
}

void Move::ResetMove()
{
    fromRow = -1;
    fromCol = -1;
    toRow = -1;
    toCol = -1;
    fromPiece = NULL;
    toPiece = NULL;
    validMove = false;
}

void Move::SetFromPiece(Piece* d)
{
    fromPiece = d;
}

void Move::SetToPiece(Piece* d)
{
    toPiece = d;
}

Piece* Move::GetFromPiece()
{
    return fromPiece;
}

Piece* Move::GetToPiece()
{
    return toPiece;
}
