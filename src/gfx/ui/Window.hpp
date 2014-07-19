#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__
#include <gfx.hpp>
#include <common.hpp>
#include <ui/Grid.hpp>
/*  Window.hpp
 *  This Header provides code relevant to create Ui windows
 *  for menus and generic interfaces like Inventories
 */
class Window
{
    public:
        Window(){}
    private:
        Grid grid;
        std::vector<image> images; //stores images associated
    protected:
};


#endif // __WINDOW_HPP__
