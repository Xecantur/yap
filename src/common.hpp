#ifndef __COMMON_HPP__
#define __COMMON_HPP__
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <stdexcept>
#include <functional>


class Velocity
{
    public:
        int x;
        int y;
    //public:
        Velocity(int xx, int yy) : x(xx), y(yy)
    {
    }
        Velocity()
        {
        }
        Velocity operator+(Velocity rhs)
        {
            Velocity tmp;
            tmp.x = this->x + rhs.x;
            tmp.y = this->y + rhs.y;
            return tmp;
        }
        Velocity operator-(Velocity rhs)
        {
            Velocity tmp;
            tmp.x = this->x - rhs.x;
            tmp.y = this->y - rhs.y;
            return tmp;
        }
        void operator+=(Velocity rhs)
        {
            this->x = this->x + rhs.x;
            this->y = this->y + rhs.y;
        }
        void operator-=(Velocity rhs)
        {
            this->x = this->x - rhs.x;
            this->y = this->y - rhs.y;
        }
};
#endif // __COMMON_HPP__
