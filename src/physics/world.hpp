#ifndef __WORLD_HPP__
#define __WORLD_HPP__
#include <physics/common.hpp>
#include <physics/actor.hpp>
class World
{
    protected:
        std::vector<Actor *> actors; //bodies to be destroyed
    public:
        World(Velocity grav)
    {
    }
        ~World()
        {
            std::vector<Actor *>::iterator actor = actors.begin();
            while(actor != actors.end())
            {
                actor++;
            }
        }

        int get()
        {
        }
        void attachActor(Actor * actor)
        {
            actors.push_back(actor);
        }
};


#endif // __WORLD_HPP__
