#pragma once

#include <SDL3/SDL.h>

class Image
{
public:

   Image() {}

   Image(const char* fName,unsigned wI,unsigned hI)
   {
      w       = wI;
      h       = hI;
      surface = SDL_LoadPNG(fName);
   }

   void set(const char* fName,unsigned wI,unsigned hI)
   {
      w       = wI;
      h       = hI;
      surface = SDL_LoadPNG(fName);
   }

   SDL_Surface* surface;
   unsigned w;
   unsigned h;
};

