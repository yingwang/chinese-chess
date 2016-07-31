//
//  Piece.cpp
//  ChineseChess
//
//  Created by Ying Wang on 19/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#include "Piece.hpp"

std::unordered_map<int, bool> Piece::PossibleMoves(std::vector< std::vector<Piece*> >& pieces)
{
    _possibleMovesAsVector.clear();
    _possibleMoves.clear();
    PossibleMovesAsVector(pieces);
    for (int i = 0; i < _possibleMovesAsVector.size(); i++)
    {
        _possibleMoves[_possibleMovesAsVector[i]] = true;
    }
    return _possibleMoves;
}

std::vector<int> Piece::PossibleMovesAsVector(std::vector< std::vector<Piece*> >& pieces)
{
    _pieces = pieces;
    return _possibleMovesAsVector;
}

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
    if ((_row == row) && (_col == col)) return false;
    return CheckGenerals(row, col);
}

bool Piece::CheckGenerals(int row, int col)
{
    if (_col == col || _col < 3 || _col > 5) return true;
    int rBlue = -1;
    int rRed = -1;
    for (int i = 0; i < Config::NUM_OF_ROW; i++)
    {
        if (_pieces[i][_col]->GetCharacter() == Piece::GENERAL_BLUE)
        {
            rBlue = i;
        }
        if (_pieces[i][_col]->GetCharacter() == Piece::GENERAL_RED)
        {
            rRed = i;
        }
    }
    if ((rBlue == -1) || (rRed == -1)) return true;
    for (int i = rBlue + 1; i < rRed; i++)
    {
        if (i == _row) continue; // this is the current move piece
        if (_pieces[i][_col]->GetCharacter() != Piece::NONE) return true;
    }
    return false;
}


