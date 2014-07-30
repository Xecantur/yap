#ifndef __GAME_HPP__
#define __GAME_HPP__
#include <common.hpp>
#include <yap.hpp>

void level_one(SDL_Renderer * rnd, SDL_Event& event, SDL_Window * window)
{
    bool done = false;
    World world(Velocity(0,10));
    Player p("assets/world/Alien.png",0,0,rnd,window,event,true);
    p.create(world.get(),22.5f, 29.0f,(*p.getSize()));
    //world.attachActor(p.getActor());
    Sprite *l = new Sprite("assets/world/platform.png",0,0,rnd,window,event,false);
    l->create(world.get(),82.5f, 16.0f, (*l->getSize()));
    Grid<Sprite> ground(0,400,200,10);
    for(int i = 0; i != 4; i++)
    {
        ground.append(*l);
        delete l;
        l = new Sprite("assets/world/platform.png",0,0,rnd,window,event,false);
        l->create(world.get(),82.5f, 16.0f, (*l->getSize()));
    }
    ground.gridify();
    SDL_Color white = {255,255,255, 0};
    TTF_Init();
    TTF_Font * font = TTF_OpenFont("main.ttf",10);
    if(font == NULL)
    {
        throw std::runtime_error("Couldn't open font");
    }
    Text test(600,50,"TrueType FONT TEST",font,20,white,rnd);
    while(!done)
    {
#ifdef DEBUG
        std::string stuff;
        p.debug();
        std::cin >> stuff;
#endif
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
        p.physics_update();
        world.get().Step(1.0f / 60.0f, 8, 3);
        world.get().ClearForces();
        SDL_RenderClear(rnd);
        p.update();
        ground.update();
        test.update();
        SDL_RenderPresent(rnd);
    }
}

void levelSelect(SDL_Renderer * rnd,SDL_Event& event, SDL_Window * window)
{
    bool done = false;
    uiWindow level_select_window("assets/ui/background.png",0,0,rnd,window);
    Texture level_select_bg("assets/ui/menu-bg.png",200,135,rnd,window);
    TTF_Font * font = TTF_OpenFont("main.ttf",50);
    SDL_Color white = {255,255,255,0};
    Text level_select(225,50,"Level Select",font,50, white, rnd);
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
        level_select.update();
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
#endif //__GAME_HPP__
