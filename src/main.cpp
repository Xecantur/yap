#include <game/mygame.hpp>

int main(int argc, char ** argv)
{
    MyGameWindow mgw("Yap",100,100,800,600);
    SDL_Event event;
    mgw.execute(event,NULL);
    SDL_Quit();
    return 0;
}
