#ifndef __GRID_HPP__
#define __GRID_HPP__
#include <common.hpp>
#include <gfx/gfx_common.hpp>

template <typename Element>
class Grid
{
    protected:
        std::vector<Element> grid_storage;
        short padding;
        short max_row_size;
        short max_col_size;
        SDL_Rect * position;
    public:
        Grid(int x = 0, int y = 0, short pad = 50, short maxRow = 3, short maxCol = 3)
        : padding(pad), max_row_size(maxRow), max_col_size(maxCol)
        {
            position = new SDL_Rect;
            position->x = x;
            position->y = y;
        }
        ~Grid()
        {
            delete position;
        }
        void update(SDL_Renderer * rnd)
        {
            typename std::vector<Element>::iterator iter = grid_storage.begin();
            short row = 0;
            short col = 1;
            SDL_Rect * current = new SDL_Rect;
            SDL_Rect * last = new SDL_Rect;
            current->x = position->x;
            current->y = position->y;
            last = current;
            int first_x_position = current->x;
            bool first_time = true;
            for(; iter != grid_storage.end(); iter++)
            {
                current = iter->getSize();
//                if(first_time != true)
                {
                    if(col != (max_col_size - 1))
                    {
                        current->x = last->x + padding;
                        col++;
                    }
                    else if(col == (max_col_size - 1))
                    {
                        current->y = last->y + padding;
                        current->x = first_x_position;
                        row++;
                        col = 0;
                    }
                }
                SDL_RenderCopy(rnd, iter->getImage(), NULL, current);
                last = current;
                if(first_time == true)
                {
                    first_time = false;                
                }
            }
        }

        void append(Element& element)
        {
            grid_storage.push_back(element);
        }
            
};

#endif // __GRID_HPP__
