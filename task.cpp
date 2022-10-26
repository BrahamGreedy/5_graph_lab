#include <graphics.h>
#include <task.h>
#include <math.h>
#include <vector>

Point points[4];

void add_point(int i, int xp, int yp)
{
   if(i > 4){
      putpixel(points[i%4].x, points[i%4].y, COLOR(142,227,239));
   }
   points[i%4].x = xp;
   points[i%4].y = yp;
   putpixel(xp, yp, COLOR(195,60,84));
   putpixel(xp, yp-1, COLOR(195,60,84));
   putpixel(xp, yp+1, COLOR(195,60,84));
   putpixel(xp+1, yp, COLOR(195,60,84));
   putpixel(xp-1, yp, COLOR(195,60,84));
}

void curve_biz(){
   double x, y;
   for(double i = 0.0; i<=1.0; i += 0.0001)
   {
      x = pow((1-i),3)*points[0].x+3*pow((1-i),2)*i*points[1].x+3*(1-i)*pow(i,2)*points[2].x+pow(i,3)*points[3].x;
      y = pow((1-i),3)*points[0].y+3*pow((1-i),2)*i*points[1].y+3*(1-i)*pow(i,2)*points[2].y+pow(i,3)*points[3].y;
      putpixel(x,y,COLOR(195,60,84));
   }
}

void lets_cut(){
   
}

void alg_chaikin()
{
   for(int i = 0; i<6; i++)
   {
      
   }
}

void save(){
   int width, height;
   IMAGE *output;

   width  = getmaxx() + 1;
   height = getmaxy() + 1;
   output = createimage(width, height);

   getimage(0, 0, width - 1, height - 1, output);
   saveBMP("output.jpg", output);
   freeimage(output);
}