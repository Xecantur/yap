#include <common.hpp>
#include <yap.hpp>

class MyGameWindow : public Window
{
    public:
    virtual bool mainLoop(SDL_Event event, void * data)
    {
        bool done = false;
        Texture bg("assets/ui/background.png",0,0,this->getRenderer());
        Sprite  ledge("assets/world/tile2.png",50,20,this->getRenderer());
        while(!done)
        {
            while(SDL_PollEvent(&event) != 0)
            {
                if(event.type == SDL_QUIT)
                {
                    done = true;
                }
                if(event.type == SDL_KEYDOWN && event.key.repeat == 0)
                {
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_q:
                            done = true;
                            break;
                    }
                }
            }
            SDL_RenderClear(this->getRenderer());
            bg.update(this->getRenderer());
            ledge.update(this->getRenderer());
            SDL_RenderPresent(this->getRenderer());
        }
        return true;
    }
    MyGameWindow(std::string title, int x, int y, int w, int h) : Window(title,x,y,w,h)
    {
    }
};

int main(int argc, char ** argv)
{
    MyGameWindow mgw("Yap",100,100,800,600);
    SDL_Event event;
    mgw.execute(event,NULL);
    SDL_Quit();
    return 0;
}
