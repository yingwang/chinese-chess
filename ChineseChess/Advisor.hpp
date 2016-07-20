//
//  Advisor.hpp
//  ChineseChess
//
//  Created by Ying Wang on 20/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#ifndef Advisor_hpp
#define Advisor_hpp

#include "Piece.hpp"

class Advisor : public Piece
{
private:
    
public:
    Advisor(int color) { character = 2 + color; }
    virtual ~Advisor() {};
    virtual std::vector<Position> PossibleMoves();
};

#endif /* Advisor_hpp */
