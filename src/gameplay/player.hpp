#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__
#include <gameplay/sprite.hpp>

class Player : public Sprite
{
    public:
        Player(std::string texname, int x, int y, SDL_Renderer * rnd,SDL_Window * window) : Sprite(texname,x,y,rnd,window)
        {
        }
};

#endif // __PLAYER_HPP__
