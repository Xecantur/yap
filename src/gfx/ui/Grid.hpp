#ifndef __GRID_HPP__
#define __GRID_HPP__
#include <common.hpp>
#include <gfx.hpp>

struct tab {
  int row;
  int col;
};

typedef struct tab table;
template <typename Element_t> class Grid {
private:
  std::vector<Element_t> grid;
  short padding; // num of px on all 4 sides so a 50px x 50px box
  SDL_Rect pos;
  short max_row_size;
  short max_col_size;

public:
  Grid(int x = 0, int y = 0, short pad = 50, short maxRow = 3, short maxCol = 3)
      : padding(pad), max_row_size(maxRow), max_col_size(maxCol) {
    pos.x = x;
    pos.y = y;
  };
  void draw(SDL_Renderer *rnd) {
    typename std::vector<Element_t>::iterator it = grid.begin();
    SDL_Rect *position = it->getSize();
    position->x = 0;
    position->y = 0;
    SDL_Rect *last = position;
    table cur;
    cur.col = 0;
    cur.row = 0;
    for (; it != grid.end(); it++) {
      if (cur.col != max_col_size) {
        position->x = last->x + padding;
        cur.col++;
      } else if (cur.col == max_col_size) {
        cur.col = 0;
      }
      if (cur.row != max_row_size) {
        position->y = last->y + padding;
        cur.row++;
      }
      SDL_RenderCopy(rnd, it->getImage().getImage(), NULL, position);
      last = position;
    }
  }
  void append(Element_t &element) { grid.push_back(element); }
};

#endif // __GRID_HPP__
