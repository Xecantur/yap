#include <common.hpp>
#include <yap.hpp>

class MyGameWindow : public Window
{
    public:
    virtual bool mainLoop(SDL_Event event, void * data)
    {
        bool done = false;
        Texture bg("assets/ui/background.png",0,0,this->getRenderer());
//        Texture logo("assets/ui/logo.png",250,0,this->getRenderer());
        Grid<Texture> logos(0,0,10);
        Texture * tmp = new Texture("assets/ui/logo.png",0,0,this->getRenderer());
        for(int t = 0; t != 8; t++)
        {
          logos.append(*tmp);
        }
        logos.gridify();
        uiWindow mainMenu("assets/ui/menu-bg.png",200,135,this->getRenderer());
//       Sprite  ledge("assets/world/tile2.png",50,20,this->getRenderer());
//       Player  player("assets/world/Alien.png",50,0,this->getRenderer());
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
  //          logo.update(this->getRenderer());
            logos.update(this->getRenderer());
            mainMenu.update(this->getRenderer());
           // ledge.update(this->getRenderer());
           // player.update(this->getRenderer());
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
    MyGameWindow mgw("Yap",100,100,1280,720);
    SDL_Event event;
    mgw.execute(event,NULL);
    SDL_Quit();
    return 0;
}
