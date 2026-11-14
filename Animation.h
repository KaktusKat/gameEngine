#pragma once

#include <cstdlib>
#include <SDL3/SDL.h>
#include "Screen.h"
#include "Image.h"

class Animation
{
public:

   Animation(Image* AlistI,unsigned* imageLengthI,unsigned lenI)
   {
      Alist       = AlistI;
      len         = lenI;
      imageLength = imageLengthI;
   }

   void play(Screen* screen,int x,int y)
   {
      screen->blit(&Alist[index],x,y);

      timer += 1;
      if(timer == imageLength[index])
      {
         index += 1;
         timer = 0;
         if(index == len)
         {
            index = 0;
         }
      }
   }

   unsigned len;
   unsigned timer = 0;
   unsigned index = 0;
   Image*   Alist;
   unsigned* imageLength;
};

