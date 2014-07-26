#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__
#include <gfx/gfx.hpp>
#include <physics/physics.hpp>

class Sprite : public Texture
{
    public:
        Sprite(std::string texname, int x, int y, SDL_Renderer * rnd) : Texture(texname,x,y,rnd)
        {
        }

};

#endif // __SPRITE_HPP__
