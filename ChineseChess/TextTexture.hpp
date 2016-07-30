//
//  TextTexture.hpp
//  ChineseChess
//
//  Created by Ying Wang on 30/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#ifndef TextTexture_hpp
#define TextTexture_hpp

#include "Header.h"
#include "Texture.hpp"

using namespace std;

class TextTexture : Texture
{
private:
    int width;
    int height;
    TTF_Font* font;
    SDL_Color textColor = {255, 255, 255, 255};
    int xOffset;
    int yOffset;
public:
    TextTexture(SDL_Renderer* r, const string& path, const string& name, const string& textToRender);
    ~TextTexture();
    void Draw(int x, int y);
    void Update(const string& textToRender);
};

#endif /* TextTexture_hpp */
