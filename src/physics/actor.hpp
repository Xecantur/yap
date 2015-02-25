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
	cpFloat box_height;
	cpFloat box_width;
	cpFloat radius;
        Actor(cpFloat x, cpFloat y, cpFloat h, cpFloat w, bool isDynamic) :
	position.x(x), position.y(y), box_height(h), box_width(w)
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
        void createBox(World world&,cpVect pos,cpFloat mass,cpFloat moment,SDL_Rect Size)
        {
		body = cpSpaceAddBody(world,cpBodyNew(mass,moment));
		cpBodySetPos(body,pos);
		position = pos;
		shape = cpSpaceAddShape(world, cpBoxShapeNew(body,box_width,box_height,radius);	
        }
        void update()
        {
		position = cpBodyGetPos(body);
		velocity = cpBodyGetVel(body);
        }
        cpBody * getBody()
        {
		return body;
        }
        void move(cpVect pos)
        {
	 cpBodySetPos(body,pos);
        }
};


#endif // __ACTOR_HPP__
