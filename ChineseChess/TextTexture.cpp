//
//  TextTexture.cpp
//  ChineseChess
//
//  Created by Ying Wang on 30/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#include "TextTexture.hpp"

using namespace std;

TextTexture::TextTexture(SDL_Renderer* r, const string& path, const string& name, const string& textToRender)
{
    renderer = r;
    font = TTF_OpenFont((path + "/" + name).c_str(), 26);
    SDL_Surface* textSurface = TTF_RenderText_Blended(font, textToRender.c_str(), textColor);
    texture = SDL_CreateTextureFromSurface(GetRenderer(), textSurface);
    width = textSurface->w;
    height = textSurface->h;
    SDL_FreeSurface(textSurface);
}

TextTexture::~TextTexture()
{
    TTF_CloseFont(font);
    font = NULL;
}

void TextTexture::Draw(int x, int y)
{
    xOffset = x;
    yOffset = y;
    SDL_Rect renderQuad = {x, y, width, height};
    SDL_RenderCopy(renderer, texture, NULL, &renderQuad);
}

void TextTexture::Update(const string& textToRender)
{
    SDL_Surface* textSurface = TTF_RenderText_Blended(font, textToRender.c_str(), textColor);
    texture = SDL_CreateTextureFromSurface(GetRenderer(), textSurface);
    width = textSurface->w;
    height = textSurface->h;
    SDL_FreeSurface(textSurface);
    Draw(xOffset, yOffset);
}