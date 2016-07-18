//
//  Texture.cpp
//  ChineseChess
//
//  Created by Ying Wang on 18/07/16.
//  Copyright © 2016 Ying. All rights reserved.
//

#include "Texture.hpp"

using namespace std;

Texture::Texture()
{
    texture = nullptr;
}

Texture::Texture(SDL_Renderer* r, const string& path, const string& name)
{
    renderer = r;
    SDL_Surface* loadedSurface = IMG_Load( (path + "/" + name).c_str() );
    assert(loadedSurface != NULL);
    texture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
    assert(texture != NULL);
    SDL_FreeSurface( loadedSurface );
}

Texture::~Texture()
{
    Free();
}

void Texture::SetRenderer(SDL_Renderer* r)
{
    renderer = r;
}

SDL_Renderer* Texture::GetRenderer()
{
    return renderer;
}

bool Texture::LoadFromFile(const string& path, const string& name)
{
    Free();
    SDL_Surface* loadedSurface = IMG_Load( (path + "/" + name).c_str() );
    assert(loadedSurface != NULL);
    texture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
    assert(texture != NULL);
    SDL_FreeSurface( loadedSurface );
    
    return texture != NULL;
}

void Texture::Free()
{
    if (texture != NULL){
        SDL_DestroyTexture(texture);
        texture = NULL;
    }
    renderer = nullptr;
}

void Texture::Draw()
{
    SDL_RenderCopy(renderer, texture, NULL, NULL);
}
