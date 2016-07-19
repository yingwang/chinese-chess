//
//  Move.hpp
//  ChineseChess
//
//  Created by Ying Wang on 19/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#ifndef Move_hpp
#define Move_hpp

#include "Piece.hpp"
#include "PieceTexture.hpp"
#include "Config.h"

class Move
{
private:
    int fromRow;
    int fromCol;
    int toRow;
    int toCol;
    bool validMove;
    Piece* fromPiece;
    Piece* toPiece;
    
    void ValidateMove();
    
public:
    Move();
    ~Move();
    
    void SetFromRow(int r);
    int GetFromRow();
    void SetFromCol(int c);
    int GetFromCol();
    void SetToRow(int r);
    int GetToRow();
    void SetToCol(int c);
    int GetToCol();
    
    void SetFromLocation(int x, int y);
    void SetToLocation(int x, int y);
    void ResetMove();
    bool GetValidMove();
    void ResetValidMove();
    
    void SetFromPiece(Piece* p);
    void SetToPiece(Piece* p);
    Piece* GetFromPiece();
    Piece* GetToPiece();
};


#endif /* Move_hpp */
