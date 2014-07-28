#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__
#include <gameplay/sprite.hpp>

class Player : public Sprite
{
    public:
        Player(std::string texname, int x, int y, SDL_Renderer * rnd,SDL_Window * window,SDL_Event& ev) : Sprite(texname,x,y,rnd,window,ev)
        {
        }
        virtual void handleEvents()
        {
            if(event->type == SDL_KEYDOWN && event->key.repeat == 0)
            {
                switch(event->key.keysym.sym)
                {
                case buttons_w:
                    this->getSize()->y -= 10;
                    break;
                case buttons_s:
                    this->getSize()->y += 10;
                    break;
                case buttons_a:
                    this->getSize()->x -= 10;
                    break;
                case buttons_d:
                    this->getSize()->x += 10;
                    break;
                case buttons_space:
                    break;
                }
            }
        }
};

#endif // __PLAYER_HPP__
