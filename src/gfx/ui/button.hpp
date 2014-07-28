#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__
#include <gfx/gfx.hpp>
#include <common.hpp>

class Button : public Texture
{
    protected:
        SDL_Rect * bounds;
    public:
        Button(std::string texname, int x, int y, SDL_Renderer *rnd) : Texture(texname,x,y,rnd)
        {
            bounds = this->getSize();
        }
        void onClick(int x, int y, std::function<void(SDL_Renderer * rnd,SDL_Event& event)> callback,SDL_Renderer *rnd,SDL_Event& event)
        {
            if(x >= bounds->x && y >= bounds->y)
            {
                if(!(x > (bounds->x+ bounds->w)) && !(y > (bounds->y + bounds->h)))
                {
                    callback(rnd,event);
                }
            }
        }
    private:
};

#endif // __BUTTON_HPP__
