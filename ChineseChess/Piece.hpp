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
#include <vector>

typedef std::pair<int, int> Position;

class Piece
{
protected:
    int character;
    int color;
    int row;
    int col;
    std::vector<Position> possibleMoves;
    
public:
    virtual std::vector<Position> PossibleMoves() = 0;
    virtual ~Piece() {};
    int GetCharacter();
    int GetColor();
    int GetRow();
    int GetCol();
    void SetRow(int r);
    void SetCol(int c);
    void SetCharacter(int c);
};

#endif /* Piece_hpp */
