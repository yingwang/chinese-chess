//
//  Elephant.hpp
//  ChineseChess
//
//  Created by Ying Wang on 20/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#ifndef Elephant_hpp
#define Elephant_hpp

#include "Piece.hpp"

class Elephant : public Piece
{
private:
    
public:
    Elephant(int color) { character = 4 + color; }
    virtual ~Elephant() {};
    virtual std::vector<Position> PossibleMoves();
};

#endif /* Elephant_hpp */
