#include <graphics.h>
#include <control.h>
#include <task.h>

Control controls[N_CONTROLS];

void create_bg(const char *file_name)
{
   IMAGE *image;
   image = loadBMP(file_name);
   putimage(0, 0, image, COPY_PUT);
   freeimage(image);
}

void create_field(int i)
{
   controls[i].left = 0;
   controls[i].top = 0;
   controls[i].right = 800;
   controls[i].bottom = 720;
}

void create_control(int i, int x0, int y0)
{
   controls[i].left = x0;
   controls[i].top = y0;
   controls[i].right = x0 + 148;
   controls[i].bottom = 800;
}

int select_control()
{
   int x, y;
   
   x = mousex();
   y = mousey();
   
   for (int i = 0; i < N_CONTROLS; i++)
   {
      if (x > controls[i].left && x < controls[i].right &&
          y > controls[i].top  && y < controls[i].bottom)
      {
         return i;
      }
   }
   
   return NONE;
}