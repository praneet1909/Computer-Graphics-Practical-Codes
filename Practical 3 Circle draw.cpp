#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
void drawcircle(int xc, int yc, int r)
{
	int d=3-2*r;
	int x=0;
	int y=r;
	
	while(y>=x)
	{
		putpixel(xc+x,yc+y,15);
		putpixel(xc+y,yc+x,15);
		putpixel(xc+y,yc-x,15);
		putpixel(xc+x,yc-y,15);
		putpixel(xc-x,yc-y,15);
		putpixel(xc-y,yc-x,15);
		putpixel(xc-y,yc+x,15);
		putpixel(xc-x,yc+y,15);
		x++;
		if(d>0)
		{
			y--;
			d=d+4*(x-y)+10;
		}
		else
		{
			d=d+4*x+6;
		}
		delay(10);
		
	}
}
    void drawline(float x1, float y1, float x2, float y2)
    {
    	float dx,dy,steps,x,y,xinc,yinc;
    	dx=abs(x2-x1);
    	dy=abs(y2-y1);
    	
    	if(dx>dy)
    	steps=dx;
    	else
    	steps=dy;
    	xinc=(x2-x1)/steps;
    	yinc=(y2-y1)/steps;
    	x=x1;
    	y=y1;
    	putpixel(round(x),round(y),15);
    	for(int k=0;k<steps;k++)
    	{
    		x=x+xinc;
    		y=y+yinc;
    		putpixel(round(x),round(y),15);
		}
	}
	int main()
	{
		int gd=DETECT,gm;
		initgraph(&gd,&gm,NULL);
		
		int x,y,r;
		float x1,y1,x2,y2,x3;
		
		cout<<"enter co-ordinates:\n";
		cout<<"x1:\n";
		cin>>x1;
		cout<<"y1:\n";
		cin>>y1;
		cout<<"x2:\n";
		cin>>x2;
		x3=(x2+x1)/2;
		y2=y1-sqrt(pow((x2-x1),2)-pow((x2-x1)/2,2));
		drawline(x1,y1,x2,y1);
		drawline(x2,y1,x3,y2);
		drawline(x1,y1,x3,y2);
		x=x3;
		y=y2+2*(y1-y2)/3;
		r=(y1-y2)/3;
		drawcircle(x,y,r);
		r=2*(y1-y2)/3;
		drawcircle(x,y,r);
		delay(50000);
		closegraph();
		return 0;	
	}
