//
//  Piece.hpp
//  ChineseChess
//
//  Created by Ying Wang on 19/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#ifndef Piece_hpp
#define Piece_hpp

#include <iostream>
#include <unordered_map>
#include <vector>
#include "Config.h"

class Piece
{
protected:
    int _character;
    int _color;
    int _row;
    int _col;
    std::vector< std::vector<Piece*> > _pieces;
    std::unordered_map<int, bool> _possibleMoves;
    
public:
    virtual std::unordered_map<int, bool> PossibleMoves(std::vector< std::vector<Piece*> >& pieces) = 0;
    virtual ~Piece() {};
    int GetCharacter();
    int GetColor() const { if (_character == 14) return -1; else return (_character % 2); };
    int GetRow();
    int GetCol();
    void SetRow(int r);
    void SetCol(int c);
    void SetCharacter(int c);
    bool InBoard(int row, int col);
    virtual bool ValidMove(int row, int col);
};

#endif /* Piece_hpp */
