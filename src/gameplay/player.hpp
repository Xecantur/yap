#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__
#include <gameplay/sprite.hpp>

class Player : public Sprite
{
    protected:
    public:
        Player(std::string texname, cpVect pos, cpVect size, SDL_Renderer * rnd,SDL_Window * window,SDL_Event& ev, bool isDynamic) : Sprite(texname,pos,size,rnd,window,ev,isDynamic)
        {
        }
        #ifdef DEBUG
        void debug()
        {
//            printf("Player Sprite(%d,%d) bbox(%f,%f) Size(%d,%d)\n--------------------------------------------\n",this->getSize()->x,this->getSize()->y,position.x,position.y,this->getSize()->w,this->getSize()->h);
        }
#endif
        virtual void handleEvents()
        {
            if(event->type == SDL_KEYDOWN && event->key.repeat == 0)
            {
                switch(event->key.keysym.sym)
                {
                case buttons_w:
                    break;
                case buttons_s:
                    break;
                case buttons_a:
                    break;
                case buttons_d:
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
                        break;
                    case buttons_s:
                        break;
                    case buttons_a:
                        break;
                    case buttons_d:
                        break;
                }
            }
        }
        virtual void update()
        {
            SDL_RenderCopy(renderer,this->getImage(), NULL, this->getSize());
        }
};

#endif // __PLAYER_HPP__
