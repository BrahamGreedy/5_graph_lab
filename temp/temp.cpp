



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
   int vertex = 4, lines_num = 3;
   Point *temp, *temp2;
   temp = new Point[vertex];
   for(int i = 0; i<vertex; i++)
   {
      temp[i] = points[i];
   }
   for(int i = 0; i < 6; i++)
   {
      temp2 = new Point[2*lines_num];
      for(int j = 0, k = 0; k < lines_num; j++, k++)
      {
         temp2[j].x = temp[k].x*0.75+temp[k+1].x*0.25;
         ++j;
         temp2[j].x = temp[k].x*0.25+_abracadabra_cast(temp[k+1]);