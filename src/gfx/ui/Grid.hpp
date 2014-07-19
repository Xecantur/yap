#ifndef __GRID_HPP__
#define __GRID_HPP__
#include <common.hpp>
#include <gfx.hpp>


template <typename Element_t>
class Grid
{
    private:
        std::vector<Element_t> grid;
        short padding; //num of px on all 4 sides so a 50px x 50px box
        SDL_Rect pos;
        short max_row_size;
        short max_col_size;
    public:
        Grid(int x = 0, int y = 0, short pad = 50, short maxRow = 3, short maxCol = 3) 
        : padding(pad), max_row_size(maxRow), max_col_size(maxCol)
        {
            pos.x = x;
            pos.y = y;
        };
        void draw(SDL_Renderer * rnd)
        {
            typename std::vector<Element_t>::iterator it = grid.begin();
            struct table
            {
                int row;
                int col;
            }cur;
            cur.row = 0;
            cur.col = 0;
            SDL_Rect p;
            SDL_Rect *position = &p;
            position->x = pos.x;
            position->y = pos.y;
            int fx = position->x; //gotta keep a reference to the first x to reset the grid;

            SDL_Rect *lastpos = position;
            SDL_Rect *yap = it->getSize();
            bool first_iteration = true;
           for(;it != grid.end(); it++)
           {
               yap = it->getSize();
               position->h = yap->h;
               position->w = yap->w;
               lastpos = position;
            if(first_iteration != true)
            {
                    if(cur.col != (max_col_size - 1))
                    {
                        position->x = lastpos->x + padding;
                        cur.col++;
                    }
               else if(cur.col == (max_col_size - 1))
               {
                   position->y = lastpos->y + padding;
                   position->x = fx;
                   cur.row++;
                   cur.col = 0;
               }
            }
               SDL_RenderCopy(rnd,it->getImage().getImage(),NULL,position);
               if(first_iteration == true)
               {
                   first_iteration = false;
               }
           }
        }
        void append(Element_t& element)
        {
            grid.push_back(element);
        }
};

#endif // __GRID_HPP__
