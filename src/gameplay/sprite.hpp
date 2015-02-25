#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__
#include <gfx/gfx.hpp>
#include <physics/physics.hpp>
#include <input/input.hpp>
class Sprite : public Texture, public Input, public Actor
{
    protected:
    public:
        Sprite(std::string texname, cpVect pos, cpVect size, SDL_Renderer * rnd,SDL_Window * window,SDL_Event& ev,bool isDynamic) : Texture(texname,pos.x,pos.y,rnd,window), Input(ev), Actor(pos,size,isDynamic)
        {
        }
        virtual void handleEvents()
        {
        }
        virtual ~Sprite(){}
};

#endif // __SPRITE_HPP__
