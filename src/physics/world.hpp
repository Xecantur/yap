#ifndef __WORLD_HPP__
#define __WORLD_HPP__
#include <physics/common.hpp>
#include <physics/actor.hpp>
class World
{
    protected:
	cpVect grav;
	cpSpace * world;
	cpFloat timestep;
        std::vector<Actor *> actors; //bodies to be destroyed
    public:
        World(cpVect gravity,cpFloat time) : grav(gravity), timestep(time)
    	{
		world = cpSpaceNew();
		cpSpaceSetGravity(world,grav);
    	}
        ~World()
        {
            std::vector<Actor *>::iterator actor = actors.begin();
            while(actor != actors.end())
            {
                actor++;
            }
	    cpSpaceFree(world);
        }

        cpSpace  * get()
        {
		return world;
        }
	virtual void update()
	{
		std::vector<Actor *>::iterator actor = actors.begin();
		while(actor != actors.end())
		{
			actor->update();
			actor++;
		}
		cpSpaceStep(world,timestep);
	}
        void attachActor(Actor * actor)
        {
            actors.push_back(actor);
        }
};


#endif // __WORLD_HPP__
