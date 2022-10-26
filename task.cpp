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

void alg_chaikin()
{
   setcolor(COLOR(195,60,84));
   int vertex = 4, size;
   bool first = true;
   //for(int i = 1; i<=6; i++)
   //{
      int N = 0;
      Point *temp = new Point[2+vertex*1];
      double dx, dy;
      if(first) size = sizeof(points)/sizeof(points[0]);
      for(int j = 0; j < size-1; j++)
      {
         Point p0 = points[j];
         Point p1 = points[j+1];
         dx = p1.x - p0.x;
         dy = p1.y - p0.y;
         temp[N].x = p0.x + dx*0.25;
         temp[N].y = p0.y + dy*0.25;
         temp[N+1].x = p0.x + dx*0.75;
         temp[N+1].y = p0.y + dy*0.75;
         N += 2;
      }
   //}
   for(int i = 0; i < 2+vertex*i-1; i++)
   {
      line(temp[i].x, temp[i].y, temp[i+1].x, temp[i+1].y);
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