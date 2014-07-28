#ifndef __INPUT_HPP__
#define __INPUT_HPP__

#define button_q SDLK_q
#define buttons_w SDLK_w
#define buttons_s SDLK_s
#define buttons_a SDLK_a
#define buttons_d SDLK_d
#define buttons_space SDLK_SPACE
#define buttons_e SDLK_e
#define buttons_i SDLK_i
#define buttons_tilda SDLK_BACKQUOTE
class Input
{
    protected:
        SDL_Event * event; 
    private:
    public:
        virtual void handleEvents()
        {
        }
    Input(SDL_Event& ev) : event(&ev)
    {
    }
};

#endif // __INPUT_HPP__
