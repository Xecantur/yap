#ifndef __GRID_HPP__
#define __GRID_HPP__
#include <common.hpp>
#include <gfx/gfx_common.hpp>

template <typename Element> class Grid {
private:
protected:
  std::vector<Element> grid;
  int padding, gx, gy;
  SDL_Rect position;

public:
  Grid(int x = 0, int y = 0, int p = 50, int gw = 3, int gh = 3) {
    padding = p;
    position.x = x; // this is the position of the first element
    position.y = y;
    gx = gw;
    gy = gh;
  }
  void gridify() {
    typename std::vector<Element>::iterator i;
    SDL_Rect *current = grid.begin()->getSize();
    SDL_Rect *last = current;
    int count = 0, row = 0;
    for (i = grid.begin(); i != grid.end(); i++) {
      if (i == grid.begin()) {
          i->getSize()->x = position.x;
          i->getSize()->y = position.y;
          last = i->getSize();
      }
      else {
        if(count != (gx - 1))
        {
            i->getSize()->x = last->x + padding;
            count++;
        } else {
            count = 0;
            i->getSize()->x = position.x;
#ifdef DEBUG
            printf("BY: %d\n", i->getSize()->y);
#endif
            i->getSize()->y = last->y + padding;
#ifdef DEBUG
            printf("AY: %d\n", i->getSize()->y);
#endif
        }
        last = i->getSize();
        }
      }
  }
  void update(SDL_Renderer *rnd) {
    typename std::vector<Element>::iterator i;
    int count = 0;
    for (i = grid.begin(); i != grid.end(); i++) {
#ifdef DEBUG
        printf("[Render[%d]] X: %d Y: %d\n",count++,i->getSize()->x, i->getSize()->y);
#endif
      SDL_RenderCopy(rnd, i->getImage(), NULL, i->getSize());
    }
  }
  void append(Element &element) { grid.push_back(element); }
};
#endif // __GRID_HPP__
