//
//  General.hpp
//  ChineseChess
//
//  Created by Ying Wang on 20/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#ifndef General_hpp
#define General_hpp

#include "Piece.hpp"
#include <iostream>
#include <vector>

class General : public Piece
{
private:

public:
    General(int color) { character = 0 + color; }
    virtual ~General() {};
    virtual std::vector<Position> PossibleMoves();
};

#endif /* General_hpp */
