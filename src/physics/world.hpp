#ifndef __WORLD_HPP__
#define __WORLD_HPP__
#include <physics/common.hpp>
#include <physics/actor.hpp>
class World
{
    protected:
        b2Vec2 gravity;
        b2World world;
        std::vector<Actor *> actors; //bodies to be destroyed
    public:
        World(Velocity grav)
        : gravity(b2Vec2(grav.x,grav.y)), world(this->gravity)
    {
    }
        ~World()
        {
            std::vector<Actor *>::iterator actor = actors.begin();
            while(actor != actors.end())
            {
                this->world.DestroyBody((*actor)->getBody());
                actor++;
            }
        }

        b2World& get()
        {
            return world;
        }
        void attachActor(Actor * actor)
        {
            actors.push_back(actor);
        }
};


#endif // __WORLD_HPP__
