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
    Cannon(int color) { _character = 10 + color; }
    virtual ~Cannon() {};
    virtual std::unordered_map<int, bool> PossibleMoves(std::vector< std::vector<Piece*> >& pieces);
    bool ValidMove(int row, int col);
};

#endif /* Cannon_hpp */
