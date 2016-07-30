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
    Chariot(int color) { _character = 8 + color; }
    virtual ~Chariot() {};
    virtual std::unordered_map<int, bool> PossibleMoves(std::vector< std::vector<Piece*> >& pieces);
    bool ValidMove(int row, int col);
};

#endif /* Chariot_hpp */
