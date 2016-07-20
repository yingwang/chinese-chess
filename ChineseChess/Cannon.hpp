//
//  Cannon.hpp
//  ChineseChess
//
//  Created by Ying Wang on 20/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#ifndef Cannon_hpp
#define Cannon_hpp

#include "Piece.hpp"

class Cannon : public Piece
{
private:
    
public:
    Cannon(int color) { character = 10 + color; }
    virtual ~Cannon() {};
    virtual std::vector<Position> PossibleMoves();
};

#endif /* Cannon_hpp */
