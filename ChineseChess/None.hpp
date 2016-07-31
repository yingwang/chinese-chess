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
    None(int color) { _character = 14; }
    virtual ~None() {};
    virtual std::unordered_map<int, bool> PossibleMoves(std::vector< std::vector<Piece*> >& pieces);
    virtual std::vector<int> PossibleMovesAsVector(std::vector< std::vector<Piece*> >& pieces);
};

#endif /* None_hpp */
