#ifndef __IMAGE_HPP__
#define __IMAGE_HPP__
#include <gfx_common.hpp>
#include <common.hpp>

class image
{
    protected:
        SDL_Texture * mImage;
        SDL_Rect mSize;
    public:
        image(int sdl_x, int sdl_y)
        {
            mSize.x = sdl_x;
            mSize.y = sdl_y;
        }
        SDL_Texture * getImage()
        {
            return mImage;
        }
        void setImage(SDL_Texture * image)
        {
            mImage = image;
        }
        SDL_Rect * getSize()
        {
            SDL_Rect * tmp = &mSize;
            return tmp;
        }
        void setPosition(int x, int y)
        {
            mSize.x = x;
            mSize.y = y;
        }
 bool LoadImage(std::string fname, SDL_Renderer * rnd)
 {
    SDL_Surface * image = IMG_Load(fname.c_str());
    if(image == NULL)
    {
        std::cout << "Unable to Load image \"" << fname << "\"" << std::endl;
        return false;
    }
    mImage = SDL_CreateTextureFromSurface(rnd,image);
    mSize.w = image->w;
    mSize.h = image->h;
    SDL_FreeSurface(image);
    return true;
 }
};


#endif // __IMAGE_HPP__
