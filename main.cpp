#include <graphics.h>
#include <control.h>
#include <task.h>
#include <time.h>

void view(){
   create_bg("bg.jpg");
   create_field(FIELD);
   create_control(PLACEMENT_END, 0, 724);
   create_control(CURVE_BIZ,162,724);
   create_control(CHAIKIN,324,724);
   create_control(SAVE,490,724);
   create_control(EXIT,650,724);
}

int main(){
   initwindow(WID, HEI, "\\(^o^)/");
   bool pe = false;
   int x_m, y_m, count_p = 0;
   view();
   while(1)
   {
      while(mousebuttons() != 1);
      switch(select_control())
      {
         case FIELD:
            if(pe) break;
            x_m = mousex();
            y_m = mousey();
            
            add_point(count_p, x_m, y_m);
            count_p++;
            delay(100);
            break;
         case PLACEMENT_END:
            pe = true;
            break;
         case CURVE_BIZ:
            if(!pe) break;
            curve_biz();
            break;
         case CHAIKIN:
            if(!pe) break;
            alg_chaikin();
            break;
         case SAVE:
            save();
            break;
         case EXIT:
            return 0;
      }
   }
}