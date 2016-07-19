//
//  PieceTexture.cpp
//  ChineseChess
//
//  Created by Ying Wang on 19/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#include "PieceTexture.hpp"

using namespace std;

PieceTexture::PieceTexture(SDL_Renderer* r, const string& path, const string& name): Texture(r, path, name)
{
}

void PieceTexture::Draw(int x, int y)
{
    SDL_Rect renderQuad = {x, y, SHAPE_WIDTH, SHAPE_HEIGHT};
    SDL_RenderCopy(renderer, texture, NULL, &renderQuad);
}

int PieceTexture::GetTotalWidth()
{
    return  SHAPE_WIDTH + MARGIN;
}

int PieceTexture::GetTotalHeight()
{
    return  SHAPE_HEIGHT + MARGIN;
}
