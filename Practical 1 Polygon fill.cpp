//Polygon Filling Using Scan Fill Algorithm (Assignment-1)
#include<graphics.h>
#include<iostream>
using namespace std;
void floodfill(int x, int y, int oldc, int newc)
{
int current;
current=getpixel(x,y);
if(current==oldc)
{
putpixel(x,y,newc);
//delay(5);
floodfill(x+1,y,oldc,newc);
floodfill(x-1,y,oldc,newc);
floodfill(x,y+1,oldc,newc);
floodfill(x,y-1,oldc,newc);
}
}
int main()
{
int x,y,oldc=0,x1,y1,x2,y2;
int gDriver=DETECT,gmode;
initgraph(&gDriver,&gmode, NULL);
cout<<"Enter the coordinates of rectangle:";
cin>>x1>>y1>>x2>>y2;
setcolor(1);
line(x1,y1,x2,y1);
//setcolor(2);
line(x2,y1,x2,y2);
//setcolor(3);
line(x2,y2,x1,y2);
setcolor(5);
line(x1,y2,x1,y1);
x=(x1+x2)/2;
y=(y1+y2)/2;
floodfill(x,y,oldc,15);
delay(500000);
closegraph();
return 0;
}
