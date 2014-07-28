#include <common.hpp>
#include <yap.hpp>

void level_one(SDL_Renderer * rnd, SDL_Event& event, SDL_Window * window)
{
    bool done = false;
    Player p("assets/world/Alien.png",0,0,rnd,window,event);
    Sprite l("assets/world/platform.png",150,100,rnd,window,event);
    while(!done)
    {
        while(SDL_PollEvent(&event) != 0)
        {
            p.handleEvents();
            if(event.type == SDL_QUIT)
            {
                done = true;
                SDL_DestroyRenderer(rnd);
                SDL_DestroyWindow(window);
                SDL_Quit();
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
        p.update();
        l.update();
        SDL_RenderPresent(rnd);
    }
}

void levelSelect(SDL_Renderer * rnd,SDL_Event& event, SDL_Window * window)
{
    bool done = false;
    uiWindow level_select_window("assets/ui/background.png",0,0,rnd,window);
    Texture level_select_bg("assets/ui/menu-bg.png",200,135,rnd,window);
    Texture level_select_text("assets/ui/level-select.png",80,-70,rnd,window);
    Button * tmp = new Button("assets/level/level-one.png",220,180,rnd,window);
    Grid<Button> levels(0,0,50,4);
    levels.append(*tmp);
    while(!done)
    {
        while(SDL_PollEvent(&event) != 0)
        {
            if(event.type == SDL_QUIT)
            {
                done = true;
                SDL_DestroyRenderer(rnd);
                SDL_DestroyWindow(window);
                SDL_Quit();
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
                        tmp->onClick(event.motion.x,event.motion.y,level_one,rnd,event,window);

                }
                
            }
        }
         SDL_RenderClear(rnd);
        level_select_window.update();
        level_select_text.update();
        level_select_bg.update();
        levels.update();
        SDL_RenderPresent(rnd);
    }
}

void startPressed(SDL_Renderer * rnd,SDL_Event& event,SDL_Window * window)
{
    levelSelect(rnd,event,window);
}


class MyGameWindow : public Window
{
    public:
    virtual bool mainLoop(SDL_Event event, void * data)
    {
        bool done = false;
        Texture bg("assets/ui/background.png",0,0,this->getRenderer(),this->getWindow());
        Texture logo("assets/ui/logo.png",250,0,this->getRenderer(),this->getWindow());
        uiWindow mainMenu("assets/ui/menu-bg.png",200,135,this->getRenderer(),this->getWindow());
        Button start("assets/ui/startbutton.png",250,150,this->getRenderer(),this->getWindow());
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
                            start.onClick(event.motion.x, event.motion.y,startPressed,this->getRenderer(),event,this->getWindow());
                    }
                }
            }
            SDL_RenderClear(this->getRenderer());
            bg.update();
            logo.update();
            mainMenu.update();
            start.update();
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
