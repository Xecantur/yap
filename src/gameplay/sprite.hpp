#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__
#include <gfx/gfx.hpp>
#include <physics/physics.hpp>
#include <input/input.hpp>
class Sprite : public Texture, public Input
{
    public:
        Sprite(std::string texname, int x, int y, SDL_Renderer * rnd,SDL_Window * window,SDL_Event& ev) : Texture(texname,x,y,rnd,window), Input(ev)
        {
        }
        virtual void handleEvents()
        {
        }
};

#endif // __SPRITE_HPP__
