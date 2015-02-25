#ifndef __WORLD_HPP__
#define __WORLD_HPP__
#include <physics/common.hpp>
#include <physics/actor.hpp>
class World
{
    protected:
	cpVect grav;
	cpSpace * pworld;
	cpFloat timestep;
        std::vector<Actor *> actors; //bodies to be destroyed
    public:
        World(cpVect gravity,cpFloat time) : grav(gravity), timestep(time)
    	{
		pworld = cpSpaceNew();
		cpSpaceSetGravity(pworld,grav);
    	}
        ~World()
        {
            std::vector<Actor *>::iterator actor = actors.begin();
            while(actor != actors.end())
            {
                actor++;
            }
	    cpSpaceFree(pworld);
        }

        cpSpace * get()
        {
		return this->pworld;
        }
	virtual void update()
	{
		std::vector<Actor *>::iterator actor = actors.begin();
		while(actor != actors.end())
		{
			(*actor)->update();
			actor++;
		}
		cpSpaceStep(pworld,timestep);
	}
        void attachActor(Actor * actor)
        {
            actors.push_back(actor);
        }
};


#endif // __WORLD_HPP__
