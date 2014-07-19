#ifndef __PHYSICS_HPP__
#define __PHYSICS_HPP__
#include <Box2D/Box2D.h>
#include <gfx.hpp>
class yapbox
{
    protected:
        b2BodyDef def;
        b2FixtureDef fixdef;
        b2Body * body;
        b2PolygonShape shape;
        b2Fixture * fixture;
        float32 density;
        float32 friction;
    public:
        b2Vec2 pos;
        b2Vec2 box; // do not use for anything but logging
        yapbox(int sdl_x, int sdl_y,bool isDynamic)
        {
            pos.x = sdl_x * PTM;
            pos.y = sdl_y * PTM;
            if(isDynamic == true)
            {
                def.type = b2_dynamicBody;
            }
            else
            {
                def.type = b2_staticBody;
            }
            def.position.Set(pos.x , pos.y);
            density = 0.0f;
            friction = 0.0f;
        }
        void setDensityAndFriction(float32 d, float32 f)
        {
            density = d;
            friction = f;
        }
        void create(b2World& world, float32 hw, float32 hh, SDL_Rect * Size)
        {
          //debug only
          box.x = hw;
          box.y = hh;
          body = world.CreateBody(&def);
          shape.SetAsBox(hw,hh, b2Vec2((Size->w / 2) * PTM, (Size->h / 2) * PTM),0.0f);
          fixdef.shape = &shape;
          fixdef.density = density;
          fixdef.friction = friction;
          fixture = body->CreateFixture(&fixdef);
        }
        void update()
        {
            if(body == NULL)
            {
                std::cout <<"Create a Body with yapbox::create()" << std::endl;
            }
            pos = body->GetPosition();
        }
        b2Body * getBody()
        { return body; }
        void move(b2Vec2 vel)
        {
            body->SetLinearVelocity(vel);
        }
};
class World
{
    protected:
        b2Vec2 gravity;
        b2World world;
    public:
        World(b2Vec2 grav) : gravity(grav), world(gravity)
    {
        gravity = grav;
    }
        b2World& get()
        {
            return world;
        }
};
#endif // __PHYSICS_HPP__
