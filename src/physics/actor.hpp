#ifndef __ACTOR_HPP__
#define __ACTOR_HPP__
#include <physics/common.hpp>

class Actor
{
    protected:
    public:
        Velocity vel;
        Actor(int x, int y, bool isDynamic)
        {
        }
        void setDensity(float32 density)
        {
        }
        void setFriction(float32 friction)
        {
        }
        void create( world, float32 hw, float32 hh, SDL_Rect Size)
        {
        }
        void physics_update()
        {
        }
        void * getBody()
        {
        }
        void move(Velocity vel)
        {
        }
};


#endif // __ACTOR_HPP__
