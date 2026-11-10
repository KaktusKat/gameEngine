#include "gameEngine.h"

int main()
{
   Screen screen(500,500);
   Image  testI("gob.png",18,17);
   bool   stop      = false;
   bool   keys[256] = {};
   float x = 200;
   float y = 200;

   while(not stop)
   {
      screen.blit(&testI,x,y);
      SDL_Event sdl_event;

      if (keys['s'])
      {
         y += 0.1;
      }
      if (keys['w'])
      {
         y -= 0.1;
      }
      
      eventLoopKeys(keys,sdl_event,&stop);      
      
      screen.refresh();
   }
}
