#include <graphics.h>
#include <control.h>
#include <task.h>

int main(){
   initwindow(WID, HEI, "\\(^o^)/");
   add_point(0, 10, 13);
   add_point(1, 100, 130);
   add_point(2, 400, 200);
   add_point(3, 7, 500);
   curve_biz();
   getch();
}