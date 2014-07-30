#ifndef __TEXT_HPP__
#define __TEXT_HPP__
#include <SDL2/SDL_ttf.h>
#include <gfx/gfx_common.hpp>
#include <common.hpp>

class Text
{
    protected:
        std::string text;
        int ptSize;
        SDL_Color color;
        SDL_Texture * rendered_text;
        TTF_Font * font;
        SDL_Renderer * renderer;
        SDL_Rect * size;
    public:
        Text(int x, int y,std::string txt,TTF_Font * FONT,int size, SDL_Color COLOR, SDL_Renderer * rnd)
        {
            renderer = rnd;
            text = txt;
            ptSize = size;
            color = COLOR;
            font = FONT;
            this->size = new SDL_Rect;
            this->size->x = x;
            this->size->y = y;
            SDL_Surface * raw_txt = TTF_RenderUTF8_Solid(font,text.c_str(),color);
            TTF_SizeText(font,text.c_str(),&this->size->w, &this->size->h);
            rendered_text = SDL_CreateTextureFromSurface(renderer,raw_txt);
            SDL_FreeSurface(raw_txt);
        }
        ~Text()
        {
        }
        void update()
        {
            SDL_RenderCopy(renderer, rendered_text, NULL, size);
        }
        void setText(std::string txt, int size = 20)
        {
            text = txt;
            if(size != ptSize)
            {
                ptSize = size;
            }
            SDL_Surface * raw_txt = TTF_RenderUTF8_Solid(font,text.c_str(),color);
            rendered_text = SDL_CreateTextureFromSurface(renderer,raw_txt);
            SDL_FreeSurface(raw_txt);
        }
        void setColor(SDL_Color COLOR)
        {
            color = COLOR;
            SDL_Surface * raw_txt = TTF_RenderUTF8_Solid(font,text.c_str(),color);
            rendered_text = SDL_CreateTextureFromSurface(renderer, raw_txt);
            SDL_FreeSurface(raw_txt);
        }
        std::string getText()
        {
            return text;
        }
};

#endif // __TEXT_HPP__
