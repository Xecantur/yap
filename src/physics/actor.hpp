#ifndef __ACTOR_HPP__
#define __ACTOR_HPP__
#include <physics/common.hpp>

class Actor
{
    protected:
        b2BodyDef bdef;
        b2FixtureDef fdef;
        b2Body * body;
        b2Fixture * fixture;
        b2PolygonShape shape;
        float32 density;
        float32 friction;
    public:
        Velocity vel;
        b2Vec2 position;
        Actor(int x, int y, bool isDynamic)
        {
            this->position.x = x * PTM;
            this->position.y = y * PTM;
            if(isDynamic == true)
            {
                this->bdef.type = b2_dynamicBody;
            }
            else
            {
                this->bdef.type = b2_staticBody;
            }
            this->bdef.position.Set(this->position.x,this->position.y);
            this->density = 0.0f;
            this->friction = 0.0f;
        }
        void setDensity(float32 density)
        {
            this->density = density;
        }
        void setFriction(float32 friction)
        {
            this->friction = friction;
        }
        void create(b2World& world, float32 hw, float32 hh, SDL_Rect Size)
        {
            this->body = world.CreateBody(&this->bdef);
            this->shape.SetAsBox(hw,hh, b2Vec2((Size.w / 2) * PTM, (Size.h / 2) * PTM), 0.0f);
            this->fdef.shape = &this->shape;
            this->fdef.density = this->density;
            this->fdef.friction = this->friction;
            this->fixture = this->body->CreateFixture(&fdef);
        }
        void physics_update()
        {
            if(body == NULL)
            {
                std::cout << "Create a body with Actor::create()" << std::endl;
            }
            position = body->GetPosition();
        }
        b2Body * getBody()
        {
            return this->body;
        }
        void move(Velocity vel)
        {
            this->body->ApplyForce(b2Vec2(vel.x * this->body->GetMass() * 10.0f, vel.y * this->body->GetMass() * 10.0f), this->body->GetWorldCenter(), true);
        }
};


#endif // __ACTOR_HPP__
