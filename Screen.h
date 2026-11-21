#pragma once

#include <SDL3/SDL.h>
#include "Image.h"

class Screen
{
public:

   Screen(unsigned wI,unsigned hI,const char* name = "screen")
   {
      w        = wI;
      h        = hI;
      window   = SDL_CreateWindow(name,wI,hI,0);
      renderer = SDL_CreateRenderer(window, "");
      surface  = SDL_CreateSurface( w, h, SDL_PIXELFORMAT_ARGB8888);
      texture  = SDL_CreateTexture(renderer,
                                  SDL_PIXELFORMAT_ARGB8888,
                                  SDL_TEXTUREACCESS_STREAMING,
                                  w, h);

      if(texture != nullptr)
      {
         SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_NONE);
      }
   }

   void blitR(SDL_Rect* rect,uint32_t col)
   {
      SDL_FillSurfaceRect(surface,rect,col);
   }

   void blit(Image* image,int x,int y)
   {
      SDL_Rect srcrect;
      srcrect.x = 0;
      srcrect.y = 0;
      srcrect.w = image->surface->w;
      srcrect.h = image->surface->h;

      SDL_Rect dstrect;
      dstrect.x = x;
      dstrect.y = y;
      dstrect.w = image->w;
      dstrect.h = image->h;

      SDL_BlitSurfaceScaled(image->surface, &srcrect, surface, &dstrect,SDL_SCALEMODE_NEAREST);
   }

   void refresh()
   {
      SDL_RenderTexture(renderer, texture, nullptr, nullptr);
      SDL_UpdateTexture(texture, nullptr, surface->pixels, surface->pitch);
      SDL_RenderPresent(renderer);
      SDL_ClearSurface(surface,0,0,0,0);
// not sure if needed
//      SDL_RenderClear(renderer);
   }

   SDL_Window*   window;
   SDL_Renderer* renderer;
   SDL_Surface*  surface;
   SDL_Texture*  texture;
   unsigned w;
   unsigned h;

};

