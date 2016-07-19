//
//  Piece.hpp
//  ChineseChess
//
//  Created by Ying Wang on 19/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#ifndef Piece_hpp
#define Piece_hpp

class Piece
{
private:
    int character;
    int color;
    int row;
    int col;
    
public:
    enum PieceCharacter
    {
        GENERAL_BLUE,
        GENERAL_RED,
        ADVISOR_BLUE,
        ADVISOR_RED,
        ELEPHANT_BLUE,
        ELEPHANT_RED,
        HORSE_BLUE,
        HORSE_RED,
        CHARIOT_BLUE,
        CHARIOT_RED,
        CANNON_BLUE,
        CANNON_RED,
        SOLDIER_BLUE,
        SOLDIER_RED,
        NONE,
    };
    Piece(Piece::PieceCharacter c);
    Piece(int c);
    int GetCharacter();
    int GetColor();
    int GetRow();
    int GetCol();
    void SetRow(int r);
    void SetCol(int c);
    void SetCharacter(int c);
};

#endif /* Piece_hpp */
