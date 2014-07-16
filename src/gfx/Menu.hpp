#ifndef __MENU_HPP__
#define __MENU_HPP__
#include <gfx.hpp>
#include <common.hpp>
class MainMenu
{
    public:
        std::vector<image> images;
        SDL_Renderer * render;
        SDL_Rect hover; //where is the mouse at
        MainMenu(SDL_Renderer * rnd) : render(rnd)
        {
            /* begin Loading and Pushing Back our images */
            image tmp(0,0);
            tmp.LoadImage("assets/ui/background.png",render);
            images.push_back(tmp);
            tmp.setPosition(200,150);
            tmp.LoadImage("assets/ui/menu-bg.png",render);
            images.push_back(tmp);
            tmp.setPosition(250,205);
            tmp.LoadImage("assets/ui/button2.png",render);
            images.push_back(tmp);
        }
        bool startPressed(int x, int y)
        {
            SDL_Rect bounds = images[2].getSize();
            if(x >= bounds.x && y >= bounds.y)
            {
                if(!(x > (bounds.x + bounds.w)) && !(y > (bounds.y + bounds.h))){
                            return true;
                  }
            }
            return false;
        }
int menuLoop(SDL_Event& event)
{
/*
 * RC 0 = Done with Menu
 * RC 1 = User wants to quit
 * RC 2 = Error
 */
    bool done = false;
    while(!done)
    {
        while(SDL_PollEvent(&event) != 0)
        {
            if(event.type == SDL_QUIT)
            {
                done = true;
                return 1;
            }
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                switch(event.button.button)
                {
                    case SDL_BUTTON_LEFT:
                       if( startPressed(hover.x,hover.y) == true)
                       {
                           done = true;
                           return 0;
                       }
                        break;
                    case SDL_BUTTON_RIGHT:
                        break;
                }
            }
            if(event.type == SDL_MOUSEMOTION)
            {
                hover.x = event.motion.x;
                hover.y = event.motion.y;
            }
            if(event.type == SDL_KEYDOWN)
            {
                if(event.key.keysym.sym == SDLK_q)
                {
                    done = true;
                    return 1;
                }
                if(event.key.keysym.sym == SDLK_c)
                {
                    done = true;
                    return 0;
                }
        }
        SDL_RenderClear(render);
        SDL_RenderCopy(render,images[0].getImage(),NULL,&(images[0].getSize()));
        SDL_RenderCopy(render,images[1].getImage(),NULL,&(images[1].getSize()));
        SDL_RenderCopy(render,images[2].getImage(),NULL,&(images[2].getSize()));
        SDL_RenderPresent(render);
        }
    }
    return 0;
}
};
#endif // __MENU_HPP__
