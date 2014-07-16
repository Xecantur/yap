#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__
#include <gfx/gfx.hpp> //player gets own sprite
#include <input/input.hpp> //player needs to be able to handle input

class player : public sprite
{
    public:
    player(int x, int y, std::string image, SDL_Renderer *rnd) : sprite(x,y,image,rnd,true)
    {
    }
    void move(b2Vec2 velc)
    {
        box.move(velc);
    }
    float32 vel;
    private:
};

#endif // __PLAYER_HPP__
