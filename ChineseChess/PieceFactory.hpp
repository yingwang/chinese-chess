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
    
    static Piece* createPiece(PieceCharacter pieceCharacter)
    {
        int color = pieceCharacter % 2;
        switch (pieceCharacter)
        {
            case GENERAL_BLUE:
            case GENERAL_RED:
                return new General(color);
                break;
            case ADVISOR_BLUE:
            case ADVISOR_RED:
                return new Advisor(color);
                break;
            case ELEPHANT_BLUE:
            case ELEPHANT_RED:
                return new Elephant(color);
                break;
            case HORSE_BLUE:
            case HORSE_RED:
                return new Horse(color);
                break;
            case CHARIOT_BLUE:
            case CHARIOT_RED:
                return new Chariot(color);
                break;
            case CANNON_BLUE:
            case CANNON_RED:
                return new Cannon(color);
                break;
            case SOLDIER_BLUE:
            case SOLDIER_RED:
                return new Soldier(color);
                break;
            default:
                return new None(color);
                break;
        }
    }
};

#endif /* PieceFactory_hpp */
