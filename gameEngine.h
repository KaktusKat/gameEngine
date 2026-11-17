#include <cstdio>
#include <SDL3/SDL.h>

void eventLoop(bool* keys, SDL_Event sdl_event, bool* mouseC, int* x, int* y, bool* stop)
{
         
   while(SDL_PollEvent(&sdl_event))
   {  
      switch(sdl_event.type)
      {  

      case(SDL_EVENT_QUIT):
         *stop = true;
         break;

      case(SDL_EVENT_KEY_DOWN):
         keys[sdl_event.key.key] = true;
         break;
            
      case(SDL_EVENT_KEY_UP):
         keys[sdl_event.key.key] = false;
         break;
      
      case(SDL_EVENT_MOUSE_BUTTON_DOWN):
         mouseC[sdl_event.button.button-1] = true;
         break;

      case(SDL_EVENT_MOUSE_BUTTON_UP):
         mouseC[sdl_event.button.button-1] = false;
         break;

      case(SDL_EVENT_MOUSE_MOTION):
         *x = sdl_event.motion.x;
         *y = sdl_event.motion.y;
         break;
      }
   }
}


