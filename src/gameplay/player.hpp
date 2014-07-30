#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__
#include <gameplay/sprite.hpp>

class Player : public Sprite
{
    protected:
        Velocity vel;
        int max_vel;
    public:
        Player(std::string texname, int x, int y, SDL_Renderer * rnd,SDL_Window * window,SDL_Event& ev, bool isDynamic) : Sprite(texname,x,y,rnd,window,ev,isDynamic)
        {
            vel.x = 0;
            vel.y = 0;
            max_vel = 5;
        }
        #ifdef DEBUG
        void debug()
        {
            printf("Player Sprite(%d,%d) bbox(%f,%f) Size(%d,%d)\n--------------------------------------------\n",this->getSize()->x,this->getSize()->y,position.x,position.y,this->getSize()->w,this->getSize()->h);
        }
#endif
        virtual void handleEvents()
        {
            if(event->type == SDL_KEYDOWN && event->key.repeat == 0)
            {
                switch(event->key.keysym.sym)
                {
                case buttons_w:
                    this->move(Velocity(0,-max_vel));
                    break;
                case buttons_s:
                    this->move(Velocity(0,max_vel));
                    break;
                case buttons_a:
                    this->move(Velocity(-max_vel,0));
                    break;
                case buttons_d:
                    this->move(Velocity(max_vel,0));
                    break;
                case buttons_space:
                    break;
                }
            }
            if(event->type == SDL_KEYUP)
            {
                switch(event->key.keysym.sym)
                {
                    case buttons_w:
                        this->move(Velocity(0,max_vel));
                        break;
                    case buttons_s:
                        this->move(Velocity(0,-max_vel));
                        break;
                    case buttons_a:
                        this->move(Velocity(max_vel,0));
                        break;
                    case buttons_d:
                        this->move(Velocity(-max_vel,0));
                        break;
                }
            }
        }
        virtual void update()
        {
            this->getSize()->x = (position.x * MTP);
            this->getSize()->y = (position.y * MTP);
            SDL_RenderCopy(renderer,this->getImage(), NULL, this->getSize());
        }
};

#endif // __PLAYER_HPP__
