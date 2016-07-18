//
//  Texture.hpp
//  ChineseChess
//
//  Created by Ying Wang on 18/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#ifndef Texture_hpp
#define Texture_hpp

#include <string>
#include "Header.h"

using namespace std;

class Texture
{
private:
protected:
    SDL_Texture* texture;
    SDL_Renderer* renderer;
public:
    Texture();
    Texture(SDL_Renderer* r, const string& path, const string& name);
    ~Texture();
    
    bool LoadFromFile(const string& path, const string& name);
    
    void Free();
    void Draw();
    
    void SetRenderer(SDL_Renderer* renderer);
    SDL_Renderer* GetRenderer();
};

#endif /* Texture_hpp */
