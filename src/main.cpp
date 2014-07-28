#include <common.hpp>
#include <yap.hpp>

void levelSelect(SDL_Renderer * rnd,SDL_Event& event)
{
    bool done = false;
    uiWindow levelSelect("assets/ui/background.png",0,0,rnd);
    Texture levelbg("assets/ui/menu-bg.png",200,135,rnd);
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
         SDL_RenderClear(rnd);
        levelSelect.update(rnd);
        levelbg.update(rnd);
        SDL_RenderPresent(rnd);
    }
}

void startPressed(SDL_Renderer * rnd,SDL_Event& event)
{
    levelSelect(rnd,event);
}


class MyGameWindow : public Window
{
    public:
    virtual bool mainLoop(SDL_Event event, void * data)
    {
        bool done = false;
        Texture bg("assets/ui/background.png",0,0,this->getRenderer());
        Texture logo("assets/ui/logo.png",250,0,this->getRenderer());
        uiWindow mainMenu("assets/ui/menu-bg.png",200,135,this->getRenderer());
        Button start("assets/ui/startbutton.png",250,150,this->getRenderer());
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
                if(event.type == SDL_MOUSEBUTTONDOWN)
                {
                    switch(event.button.button)
                    {
                        case SDL_BUTTON_LEFT:
                            start.onClick(event.motion.x, event.motion.y,startPressed,this->getRenderer(),event);
                    }
                }
            }
            SDL_RenderClear(this->getRenderer());
            bg.update(this->getRenderer());
            logo.update(this->getRenderer());
            mainMenu.update(this->getRenderer());
            start.update(this->getRenderer());
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
