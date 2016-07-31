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
    Horse(int color) { _character = 6 + color; }
    virtual ~Horse() {};
    virtual std::unordered_map<int, bool> PossibleMoves(std::vector< std::vector<Piece*> >& pieces);
    virtual std::vector<int> PossibleMovesAsVector(std::vector< std::vector<Piece*> >& pieces);
    bool ValidMove(int row, int col);
};

#endif /* Horse_hpp */
