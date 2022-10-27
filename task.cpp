#include <graphics.h>
#include <task.h>
#include <math.h>

Point points[4];

void add_point(int i, int xp, int yp)
{
   if(i > 3){
      putpixel(points[i%4].x, points[i%4].y, COLOR(142,227,239));
      putpixel(points[i%4].x, points[i%4].y-1, COLOR(142,227,239));
      putpixel(points[i%4].x, points[i%4].y+1, COLOR(142,227,239));
      putpixel(points[i%4].x+1, points[i%4].y, COLOR(142,227,239));
      putpixel(points[i%4].x-1, points[i%4].y, COLOR(142,227,239));
   }
   points[i%4].x = xp;
   points[i%4].y = yp;
   putpixel(xp, yp, COLOR(195,60,84));
   putpixel(xp, yp-1, COLOR(195,60,84));
   putpixel(xp, yp+1, COLOR(195,60,84));
   putpixel(xp+1, yp, COLOR(195,60,84));
   putpixel(xp-1, yp, COLOR(195,60,84));
}

void curve_biz()
{
   double x, y;
   for(double i = 0.0; i<=1.0; i += 0.0001)
   {
      x = pow((1-i),3)*points[0].x+3*i*pow((1-i),2)*points[1].x+3*i*i*(1-i)*points[2].x+pow(i,3)*points[3].x;
      y = pow((1-i),3)*points[0].y+3*i*pow((1-i),2)*points[1].y+3*i*i*(1-i)*points[2].y+pow(i,3)*points[3].y;
      putpixel(x,y,COLOR(195,60,84));
   }
}

void alg_chaikin()
{
   setcolor(COLOR(195,60,84));
   int vertex = 4, size;
   bool first = true;
   Point *temp2 = new Point[2+vertex];
   for(int i = 1; i<=6; i++)
   {
      int N = 0, k = 0;
      Point *temp = new Point[2+vertex*i];
      double dx, dy;
      Point p0, p1;
      if(first)
      {
         size = sizeof(points)/sizeof(points[0]);
         for(int j = 0; j<size-1;j++)
         {
            p0 = points[j];
            p1 = points[j+1];
            dx = p1.x - p0.x;
            dy = p1.y - p0.x;
            temp[k].x = p0.x+dx*0.25;
            temp[k+1].x = p0.x + dx*0.75;
            temp[k].y = p0.y+dy*0.25;
            temp[k+1].y = p0.y + dy*0.75;
            k += 2;
         }
      }
      else
      {
         size = sizeof(temp2)/sizeof(temp2[0]);
         for(int j = 0; j<size-1;j++)
         {
            p0 = temp2[j];
            p1 = temp2[j+1];
            dx = p1.x - p0.x;
            dy = p1.y - p0.x;
            temp[k].x = p0.x+dx*0.25;
            temp[k+1].x = p0.x + dx*0.75;
            temp[k].y = p0.y+dy*0.25;
            temp[k+1].y = p0.y + dy*0.75;
            k += 2;
         }
      }
      k = 0;
      Point *temp2 = new Point[2+vertex*i];
      for(int j = 0; j < 2+vertex*i; j++)
      {
         temp2[i].x = temp[i].x;
         temp2[i].y = temp[i].y;
      }
   }
   temp2[0] = points[0];
   temp2[size-1] = points[3];
   for(int i = 0; i<size-1; i++)
   {
      line(temp2[i].x, temp2[i].y, temp2[i+1].x, temp2[i+1].y);
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