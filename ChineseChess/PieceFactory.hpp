//
//  PieceFactory.hpp
//  ChineseChess
//
//  Created by Ying Wang on 20/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#ifndef PieceFactory_hpp
#define PieceFactory_hpp

#include <iostream>
#include "Piece.hpp"
#include "General.hpp"
#include "Advisor.hpp"
#include "Elephant.hpp"
#include "Horse.hpp"
#include "Chariot.hpp"
#include "Cannon.hpp"
#include "Soldier.hpp"
#include "None.hpp"

class PieceFactory
{
public:
    static Piece* createPiece(Piece::PieceCharacter pieceCharacter)
    {
        int color = pieceCharacter % 2;
        switch (pieceCharacter)
        {
            case Piece::GENERAL_BLUE:
            case Piece::GENERAL_RED:
                return new General(color);
                break;
            case Piece::ADVISOR_BLUE:
            case Piece::ADVISOR_RED:
                return new Advisor(color);
                break;
            case Piece::ELEPHANT_BLUE:
            case Piece::ELEPHANT_RED:
                return new Elephant(color);
                break;
            case Piece::HORSE_BLUE:
            case Piece::HORSE_RED:
                return new Horse(color);
                break;
            case Piece::CHARIOT_BLUE:
            case Piece::CHARIOT_RED:
                return new Chariot(color);
                break;
            case Piece::CANNON_BLUE:
            case Piece::CANNON_RED:
                return new Cannon(color);
                break;
            case Piece::SOLDIER_BLUE:
            case Piece::SOLDIER_RED:
                return new Soldier(color);
                break;
            default:
                return new None(color);
                break;
        }
    }
};

#endif /* PieceFactory_hpp */
