#ifndef CONTROL_H
#define CONTROL_H

enum control_values { NONE = -1, EXIT, SAVE, CURVE_BIZ, CHAIKIN, PLACEMENT_END, FIELD, N_CONTROLS};

struct Control
{
   int left;
   int top;
   int right;
   int bottom;
};

void create_bg(const char *);
void create_control(int,int,int);
void create_field(int);
int select_control();

#endif