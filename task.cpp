#include <graphics.h>
#include <task.h>
#include <math.h>

Point points[4];

void add_point(int i, int xp, int yp)
{
   points[i].x = xp;
   points[i].y = yp;
}

void curve_biz(){
   double x, y;
   for(double i = 0.0; i<=1.0; i += 0.001)
   {
      x = pow((1-i),3)*points[0].x+3*pow((1-i),2)*i*points[1].x+3*(1-i)*pow(i,2)*points[2].x+pow(i,3)*points[3].x;
      y = pow((1-i),3)*points[0].y+3*pow((1-i),2)*i*points[1].y+3*(1-i)*pow(i,2)*points[2].y+pow(i,3)*points[3].y;
      putpixel(x,y,WHITE);
   }
}