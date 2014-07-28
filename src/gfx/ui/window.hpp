#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__
#include <gfx/gfx.hpp>
#include <common.hpp>

// class window is a wrapper for SDL windows
class Window
{
    protected:
        SDL_Renderer * renderer;
        SDL_Window * window;
        int window_height;
        int window_width;
        bool done; //done using the window ?
    public:
        Window(std::string title, int x, int y, int w, int h)
        {
            if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
            {
                throw std::runtime_error("Couldn't Start SDL!\n");
            }
            window = SDL_CreateWindow(title.c_str(),x,y,w,h,SDL_WINDOW_SHOWN);
            if(window == NULL)
            {
                throw std::runtime_error("Couldn't Create a Window!\n");
            }
            renderer = SDL_CreateRenderer(window,1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if(renderer == NULL)
            {
                throw std::runtime_error("Couldn't Create Renderer!\n");
            }
        }
        SDL_Renderer * getRenderer()
        {
            return renderer;
        }
        SDL_Window * getWindow()
        {
            return window;
        }
        virtual bool mainLoop(SDL_Event event,void * data)
        {
            return true;
        }
        bool execute(SDL_Event event,void * data)
        {
            done = mainLoop(event,data);
            return done;
        }
        ~Window()
        {
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
        }
};

//class uiWindow is for ui windows like those that contain menus
class uiWindow : public Texture
{
    protected:
        std::vector<Button> buttons;
    public:
        uiWindow(std::string texname, int x, int y, SDL_Renderer * rnd,SDL_Window * window) : Texture(texname,x,y,rnd,window)
        {
        }
};
#endif // __WINDOW_HPP__
