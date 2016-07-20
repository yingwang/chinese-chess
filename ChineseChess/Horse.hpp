//
//  Horse.hpp
//  ChineseChess
//
//  Created by Ying Wang on 20/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#ifndef Horse_hpp
#define Horse_hpp

#include "Piece.hpp"

class Horse : public Piece
{
private:
    
public:
    Horse(int color) { character = 6 + color; }
    virtual ~Horse() {};
    virtual std::vector<Position> PossibleMoves();
};

#endif /* Horse_hpp */
