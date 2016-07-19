//
//  Level.cpp
//  ChineseChess
//
//  Created by Ying Wang on 19/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#include "Level.hpp"

std::vector<int> Level::GetMap()
{
    return map;
}

int Level::GetNumOfRow()
{
    return numOfRow;
}

int Level::GetNumOfCol()
{
    return numOfCol;
}