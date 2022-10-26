


Point points[3];

void add_point(int i, int xp, int yp)
{
   points[i].x = xp;
   points[i].y = yp;
}

void curve_biz(){
   double x, y;
   for(double i = 0.0; i<=1.0; i += 0.01)
   {
      x = pow((1-i),3)*_abracadabra_cast(points[0]);