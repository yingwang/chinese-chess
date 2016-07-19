//
//  PieceTexture.hpp
//  ChineseChess
//
//  Created by Ying Wang on 19/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#ifndef PieceTexture_hpp
#define PieceTexture_hpp

#include "Header.h"
#include "Texture.hpp"

using namespace std;

class PieceTexture : public Texture
{
private:
    static const int SHAPE_WIDTH = 76;
    static const int SHAPE_HEIGHT = 76;
    static const int MARGIN = 2;
    
public:
    PieceTexture(SDL_Renderer* r, const string& path, const string& name);
    void Draw(int x, int y);
    static int GetTotalWidth();
    static int GetTotalHeight();
};


#endif /* PieceTexture_hpp */
