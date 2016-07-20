//
//  None.hpp
//  ChineseChess
//
//  Created by Ying Wang on 21/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#ifndef None_hpp
#define None_hpp

#include "Piece.hpp"
#include <iostream>
#include <vector>

class None : public Piece
{
private:
    
public:
    None(int color) { character = 14; }
    virtual ~None() {};
    virtual std::vector<Position> PossibleMoves();
};

#endif /* None_hpp */
