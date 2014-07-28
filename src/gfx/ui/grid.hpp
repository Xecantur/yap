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
    SDL_Rect *last = grid.begin()->getSize();
    int count = 0;
    for (i = grid.begin(); i != grid.end(); i++) {
      if (i == grid.begin()) {
          i->getSize()->x = position.x;
          i->getSize()->y = position.y;
          last = i->getSize();
#ifdef DEBUG
          std::cout << "First Grid Element: " << i->getSize()->x << " , " << i->getSize()->y << std::endl;
#endif
      }
      else {
        if(count != (gx - 1))
        {
            i->getSize()->x = last->x + padding;
            i->getSize()->y = last->y;
            count++;
        } else {
            count = 0;
            i->getSize()->x = position.x;
            i->getSize()->y = last->y + padding;
        }
        last = i->getSize();
        }
      }
  }
  void update() {
    typename std::vector<Element>::iterator i;
    int count = 0;
    SDL_Rect * warn_if_same_pos = grid.begin()->getSize();
    int warn_count = 0;
    for (i = grid.begin(); i != grid.end(); i++) {
#ifndef NO_WARNINGS
        if(i->getSize()->x == warn_if_same_pos->x
                &&
           i->getSize()->y == warn_if_same_pos->y)
        {
            warn_count++;
        }
        if(warn_count > 2)
        {
            printf("Warning!!!! you may be using the same object over and over again!\nuse object *  name = new * object(args); in your population routine: gridObject.append(*object); delete name; name = new * object(args);\n");
        }
#endif
#ifdef DEBUG
        printf("Render[%d]: at (%d,%d)\n",count++,i->getSize()->x,i->getSize()->y);
#endif

      SDL_RenderCopy(i->getRenderer(), i->getImage(), NULL, i->getSize());
      warn_if_same_pos = i->getSize();
    }
  }
  void append(Element &element) { grid.push_back(element); }
};
#endif // __GRID_HPP__
