#include <cstdio>
#include <SDL3/SDL.h>

class Image
{
public:

   Image(const char* fName,unsigned wI,unsigned hI)
   {
      w       = wI;
      h       = hI;
      surface = SDL_LoadPNG(fName);
   }

   SDL_Surface* surface;
   unsigned w;
   unsigned h;
};

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

   void blit(Image* image,int x,int y)
   {
      SDL_Rect srcrect;
      srcrect.x = 0;
      srcrect.y = 0;
      srcrect.w = image->w;
      srcrect.h = image->h;

      SDL_Rect dstrect;
      dstrect.x = x;
      dstrect.y = y;
      dstrect.w = image->w;
      dstrect.h = image->h;

      SDL_BlitSurface(image->surface, &srcrect, surface, &dstrect);
   }

   void refresh()
   {
      SDL_UpdateTexture(texture, nullptr, surface->pixels, surface->pitch);
      SDL_RenderTexture(renderer, texture, nullptr, nullptr);
      SDL_RenderPresent(renderer);
   }

   
   SDL_Window*   window; 
   SDL_Renderer* renderer;
   SDL_Surface*  surface;
   SDL_Texture*  texture;
   unsigned w;
   unsigned h;

};

void eventLoopKeys(bool* keys,SDL_Event sdl_event,bool* stop)
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
      }
   }
}
