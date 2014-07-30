#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__
#include <gfx/gfx.hpp>
#include <physics/physics.hpp>
#include <input/input.hpp>
class Sprite : public Texture, public Input, public Actor
{
    protected:
    public:
        Sprite(std::string texname, int x, int y, SDL_Renderer * rnd,SDL_Window * window,SDL_Event& ev,bool isDynamic) : Texture(texname,x,y,rnd,window), Input(ev), Actor(x,y,isDynamic)
        {
        }
        virtual void handleEvents()
        {
        }
};

#endif // __SPRITE_HPP__
