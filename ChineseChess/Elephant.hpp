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
    Elephant(int color) { _character = 4 + color; }
    virtual ~Elephant() {};
    virtual std::unordered_map<int, bool> PossibleMoves(std::vector< std::vector<Piece*> >& pieces);
    virtual std::vector<int> PossibleMovesAsVector(std::vector< std::vector<Piece*> >& pieces);
    bool ValidMove(int row, int col);
};

#endif /* Elephant_hpp */
