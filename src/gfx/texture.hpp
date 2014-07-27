#ifndef __TEXTURE_HPP__
#define __TEXTURE_HPP__
#include <gfx/gfx_common.hpp>
class Texture
{
    protected:
        SDL_Rect * size;
        SDL_Texture * tex;
        std::string title;
    public:
        Texture(std::string texname, int x, int y, SDL_Renderer * rnd)
        {
            title = texname;
            size = new SDL_Rect;
            size->x = x;
            size->y = y;
            SDL_Surface * tmp = IMG_Load(texname.c_str());
            if(tmp == NULL)
            {
                std::cout << "Unable to Load Image \"" << texname << "\"" <<  std::endl;
                SDL_FreeSurface(tmp);
                throw std::runtime_error("Unable to Load Image: "+texname);
            }
            tex = SDL_CreateTextureFromSurface(rnd,tmp);
            size->w = tmp->w;
            size->h = tmp->h;
            SDL_FreeSurface(tmp);
        }
        SDL_Texture * getImage()
        {
            return tex;
        }
        std::string getTitle()
        {
            return title;
        }
        void setImage(SDL_Texture * img_name)
        {
            tex = img_name;
        }
        SDL_Rect * getSize()
        {
            return size;
        }
        
        void update(SDL_Renderer * rnd)
        {
            SDL_RenderCopy(rnd,this->getImage(), NULL, this->getSize());
        }
    private:
};

#endif // __TEXTURE_HPP__
