#ifndef __GRID_HPP__
#define __GRID_HPP__
#include <common.hpp>
#include <gfx/gfx_common.hpp>


template <typename Element>
class Grid
{
    private:
    protected:
        std::vector<Element> grid;
        int padding,gx,gy;
        SDL_Rect position;
    public:
        Grid(int x = 0, int y = 0, int p = 50, int gw = 3, int gh = 3)
        {
            padding = p;
            position.x = x; //this is the position of the first element
            position.y = y;
            gx = gw;
            gy = gh;
        }
        void gridify()
        {
            typename std::vector<Element>::iterator i;
            SDL_Rect * current = grid.begin()->getSize();
            SDL_Rect * last = current;
            int count = 0, row = 0;
            for(i = grid.begin(); i != grid.end(); i++)
            {
               if(i == grid.begin())
               {
#ifdef DEBUG
                   printf("First Element\n");
                   printf("X: %d Y: %d\n", i->getSize()->x, i->getSize()->y);
#endif
                   i->getSize()->x = position.x;
                   i->getSize()->y = position.y;
#ifdef DEBUG
                   printf("After Assignment(First Element)\n");
                   printf("X: %d Y: %d\n", i->getSize()->x, i->getSize()->y);
#endif
                   last = i->getSize();
               }
               else
               {
                    if(count != gx)
                    {
#ifdef DEBUG
                        printf("Before assign X: %d\n",i->getSize()->x);
#endif
                        i->getSize()->x = last->x + padding;
#ifdef DEBUG
                        printf("After assign X: %d\n",i->getSize()->x);
#endif
                        count++;
                    }
                    else
                    {
                        count = 0;
                        row++;
                        i->getSize()->x = position.x;
                        i->getSize()->y = last->x + padding;
                    }
               }
            }
        }
        void update(SDL_Renderer * rnd)
        {
            typename std::vector<Element>::iterator i;
            for(i = grid.begin(); i != grid.end(); i++)
            {
            SDL_RenderCopy(rnd, i->getImage(), NULL, i->getSize());
            }
        }
        void append(Element& element)
        {
            grid.push_back(element);
        }
};
#endif // __GRID_HPP__
