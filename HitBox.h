#pragma once

class HitBox
{
public:

   HitBox(int* xI,int* yI,unsigned wI,unsigned hI,const char* codeI)
   {
      x    = xI;
      y    = yI;
      w    = wI;
      h    = hI;
      code = codeI;
   }

   bool isHitXY(int Ox,int Oy,unsigned Ow,unsigned Oh,const char* code)
   {
      topX = (*x) + w;
      topY = (*y) + h;

      int OtopX = Ox+Ow;
      int OtopY = Oy+Oh;

      return(Ox < topX) and (OtopX > *x) and 
            (Oy < topY) and (OtopY > *y);
   }

   bool isHit(HitBox otherH,const char* code)
   {
      return isHitXY(*otherH.x,*otherH.y,otherH.w,otherH.h,code);
   }

   int*        x;
   int*        y;
   int         topX;
   int         topY;
   unsigned    w;
   unsigned    h;
   const char* code;
};
