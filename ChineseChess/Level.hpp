//
//  Level.hpp
//  ChineseChess
//
//  Created by Ying Wang on 19/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#ifndef Level_hpp
#define Level_hpp

#include <vector>
#include "Header.h"
#include "Piece.hpp"

/*
 GENERAL_BLUE = 0,
 GENERAL_RED = 1,
 ADVISOR_BLUE = 2,
 ADVISOR_RED = 3,
 ELEPHANT_BLUE = 4,
 ELEPHANT_RED = 5,
 HORSE_BLUE = 6,
 HORSE_RED = 7,
 CHARIOT_BLUE = 8,
 CHARIOT_RED = 9,
 CANNON_BLUE = 10,
 CANNON_RED = 11,
 SOLDIER_BLUE = 12,
 SOLDIER_RED = 13,
 NONE = 14,
 */

using namespace std;

class Level
{
private:
    int numOfRow = 10;
    int numOfCol = 9;
    vector<int> map =
    {
        8,6,4,2,0,2,4,6,8,
        14,14,14,14,14,14,14,14,14,
        14,10,14,14,14,14,14,10,14,
        12,14,12,14,12,14,12,14,12,
        14,14,14,14,14,14,14,14,14,
        14,14,14,14,14,14,14,14,14,
        13,14,13,14,13,14,13,14,13,
        14,11,14,14,14,14,14,11,14,
        14,14,14,14,14,14,14,14,14,
        9,7,5,3,1,3,5,7,9,
    };
    int time;
    int moves;
    
public:
    vector<int> GetMap();
    int GetNumOfRow();
    int GetNumOfCol();
};

#endif /* Level_hpp */
