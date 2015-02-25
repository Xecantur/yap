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
        void setDensity(float density)
        {
        }
        void setFriction(float friction)
        {
        }
        void create( int  world, float hw, float hh, SDL_Rect Size)
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
