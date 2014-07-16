#include <gfx/gfx.hpp>
#include <gfx/Menu.hpp>
#include <gameplay/game.hpp>
#include <audio/audio.hpp>
#include <input/input.hpp>
#include <physics/physics.hpp>
#include <common.hpp>
/*
	P2M = 50.0f;
	M2P = 1.0f/5w0.0f
*/
int main(int argc, char **argv) {

  SDL_Renderer *render;
  SDL_Window *window;
  int window_width = 800;
  int window_height = 600;
  bool done = false;
  SDL_Event event;

  World world(b2Vec2(0.0f, 40.0f));
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cout << "[SDL]: Initializing Error, ";
    std::cout << SDL_GetError() << std::endl;
    return -1;
  }
  window = SDL_CreateWindow("Yap", 100, 100, window_width, window_height,SDL_WINDOW_SHOWN);
  if (window == NULL) {
    std::cout << "[SDL]: Unable to Create Window, ";
    std::cout << SDL_GetError()
              << std::endl;
    return -2;
  }
  render = SDL_CreateRenderer(window, 1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (render == NULL) {
    std::cout << "[SDL]: Failed to Create Renderer, ";
    std::cout << SDL_GetError() << std::endl;
    return -3;
  }
  MainMenu mainMenu(render);
  player test(100,200,"assets/world/Alien.png",render);
  sprite plat(100,245,"assets/world/tile2.png",render,false);
  sprite platform(350,200,false);
  platform.setImage(plat.getImage());
  test.getBox().create(world.get(),22.5f, 29.0f,test.getImage().getSize());
  plat.getBox().create(world.get(), 82.5f, 16.0f,plat.getImage().getSize());
  platform.getBox().create(world.get(),82.5,16.0f,platform.getImage().getSize());
  test.vel = 90.0f;
  int result = mainMenu.menuLoop(event);
  if(result == 1)
  {
      goto END;
  }
  while (!done) {
    while (SDL_PollEvent(&event) != 0) {
      if (event.type == SDL_QUIT) {
        done = true;
      }
      if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
        switch (event.key.keysym.sym) {
        case SDLK_q:
          done = true;
          break;
        case SDLK_w:
          test.move(b2Vec2(0.0f,-test.vel*4));
          break;
        case SDLK_s:
          test.move(b2Vec2(0.0f,test.vel));
          break;
        case SDLK_a:
          test.move(b2Vec2(-test.vel,0.0f));
          break;
        case SDLK_d:
          test.move(b2Vec2(test.vel,0.0f));
          break;
        case SDLK_m:
          if(mainMenu.menuLoop(event) == 1)
          { done = true; goto END;}
          break;
        }
      }
      if (event.type == SDL_KEYUP && event.key.repeat == 0) {
        switch (event.key.keysym.sym) {
        case SDLK_w:
            test.move(b2Vec2(0.0f,test.vel));
          break;
        case SDLK_s:
            test.move(b2Vec2(0.0f,-test.vel));
          break;
        case SDLK_a:
            test.move(b2Vec2(test.vel,0.0f));
          break;
        case SDLK_d:
            test.move(b2Vec2(-test.vel,0.0f));
          break;
        }
      }
    }
    world.get().Step(1.0f / 60.0f, 8, 3);
    SDL_RenderClear(render);
    test.draw(render);
    plat.draw(render);
    platform.draw(render);
    SDL_RenderPresent(render);
 /*while ! done*/ }
END:
  SDL_DestroyRenderer(render);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
