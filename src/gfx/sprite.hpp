#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__
#include <image.hpp>
#include <physics/physics.hpp>
class sprite 
{
protected:
    image texture;
    yapbox box;
public:
 sprite(int sdl_x, int sdl_y,std::string image,SDL_Renderer * rnd,bool isDynamic) : texture(sdl_x,sdl_y), box(sdl_x,sdl_y,isDynamic)
 {
     texture.LoadImage(image,rnd);
 }
 sprite(int x, int y, bool isDynamic) : texture(x,y), box(x,y,isDynamic)
 {
 }
 void draw(SDL_Renderer * rnd)
 {
    box.update();
    SDL_Rect * local = &(texture.getSize());
    local->x = box.pos.x;
    local->y = box.pos.y;
    SDL_RenderCopy(rnd, texture.getImage(), NULL, local);
 }

 yapbox& getBox()
 {
     return box;
 }
 image& getImage()
 {
     return texture;
 }
 void setImage(image& img)
 {
     texture = img;
 }
};
#endif // __SPRITE_HPP__
