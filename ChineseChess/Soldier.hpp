//
//  Soldier.hpp
//  ChineseChess
//
//  Created by Ying Wang on 20/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#ifndef Soldier_hpp
#define Soldier_hpp

#include "Piece.hpp"

class Soldier : public Piece
{
private:
    
public:
    Soldier(int color) { character = 12 + color; }
    virtual ~Soldier() {};
    virtual std::vector<Position> PossibleMoves();
};

#endif /* Soldier_hpp */
