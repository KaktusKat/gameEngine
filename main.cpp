#include "HitBox.h"
#include "Screen.h"
#include "Animation.h"
#include "Image.h"
#include "gameEngine.h"

int main()
{
   Image animationL[2];
   unsigned imageLength[2] = {100,100};
   Screen screen(500,500);
   Image  testI("gob.png",50,50);
   bool   stop      = false;
   bool   keys[256] = {};
   bool   mouseC[3] = {};
   int    animate   = 0;
   int Mx           = 0;
   int My           = 0;
   int x            = 200;
   int y            = 200;
   SDL_Rect rect    = makeRect(0,0,500,500);

   animationL[0].set("gobWalk.png", 50, 50);
   animationL[1].set("gobWalk2.png", 50, 50);
   Animation walk(animationL,imageLength,2);

   HitBox playerH(&x,&y,50,50,"any");
   HitBox mouseH(&Mx,&My,1,1,"any");

   while(not stop)
   {
      screen.blitR(&rect);

      SDL_Event sdl_event;

      if (keys['s'])
      {
         y += 1;
         animate += 1;
      }
      if (keys['w'])
      {
         y -= 1;
         animate -= 1;
      }

      if (playerH.isHit(mouseH,"any") and mouseC[2])
      {
         mouseC[2] = false;
         testI.w  -= 1;
         testI.h  -= 1;
      }

      if(animate != 0)
      {
         animate = 0;
         walk.play(&screen,x,y);
      }
      else
      {
         screen.blit(&testI,x,y);
      }

      if (mouseC[0])
      {
         mouseC[0] = false;
         x         = Mx;
         y         = My; 
      }
      
      eventLoop(keys, sdl_event, mouseC, &Mx, &My, &stop);      
      
      screen.refresh();
   }
}
