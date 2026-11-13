#include "gameEngine.h"

int main()
{
   Screen screen(500,500);
   Image  testI("gob.png",50,50);
   bool   stop      = false;
   bool   keys[256] = {};
   bool   mouseC    = false;
   unsigned Mx      = 0;
   unsigned My      = 0;
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
      if (mouseC)
      {
         x -= 0.1; 
      }
      
      eventLoop(keys,sdl_event,&mouseC,&Mx,&My,&stop);      
      
      screen.refresh();
   }
}
