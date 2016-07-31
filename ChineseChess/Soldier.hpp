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
    Soldier(int color) { _character = 12 + color; }
    virtual ~Soldier() {};
    virtual std::vector<int> PossibleMovesAsVector(std::vector< std::vector<Piece*> >& pieces);
    bool ValidMove(int row, int col);
};

#endif /* Soldier_hpp */
