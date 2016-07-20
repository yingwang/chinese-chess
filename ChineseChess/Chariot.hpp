//
//  Chariot.hpp
//  ChineseChess
//
//  Created by Ying Wang on 20/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#ifndef Chariot_hpp
#define Chariot_hpp

#include "Piece.hpp"

class Chariot : public Piece
{
private:
    
public:
    Chariot(int color) { character = 8 + color; }
    virtual ~Chariot() {};
    virtual std::vector<Position> PossibleMoves();
};

#endif /* Chariot_hpp */
