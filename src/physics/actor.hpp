#ifndef __ACTOR_HPP__
#define __ACTOR_HPP__
#include <physics/common.hpp>
class Actor
{
    protected:
    public:
        cpVect position;
	cpVect velocity;
	cpBody * body;
	cpShape * shape;
	cpVect size;
	cpFloat radius;
	bool dynamic;
        Actor(cpVect pos, cpVect sz, bool isDynamic) :
	position(pos), size(sz), dynamic(isDynamic)
        {
		radius = 1;	
        }
	~Actor()
	{
		cpShapeFree(shape);
		cpBodyFree(body);
	}
        void setDensity(float density)
        {
        }
        void setFriction(float friction)
        {
	  cpShapeSetFriction(shape,friction);
        }
        void createBox(World w,cpVect pos,cpFloat mass,cpFloat moment,SDL_Rect Size)
        {
		if(dynamic == true)
		{
			body = cpSpaceAddBody(w,cpBodyNew(mass,moment));
		}
		else{
			body = cpSpaceAddBody(w->staticBody,cpBodyNew(mass,moment));
		}
		cpBodySetPosition(body,pos);
		position = pos;
		shape = cpSpaceAddShape(w, cpBoxShapeNew(body,size.x,size.y,radius);	
        }
        void update()
        {
		position = cpBodyGetPosition(body);
		velocity = cpBodyGetVelocity(body);
        }
        cpBody * getBody()
        {
		return body;
        }
        void move(cpVect pos)
        {
	 cpBodySetPosition(body,pos);
        }
};


#endif // __ACTOR_HPP__
