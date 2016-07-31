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
    Advisor(int color) { _character = 2 + color; }
    virtual ~Advisor() {};
    virtual std::unordered_map<int, bool> PossibleMoves(std::vector< std::vector<Piece*> >& pieces);
    virtual std::vector<int> PossibleMovesAsVector(std::vector< std::vector<Piece*> >& pieces);
    bool ValidMove(int row, int col);
};

#endif /* Advisor_hpp */
