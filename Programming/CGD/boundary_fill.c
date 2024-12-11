#include<conio.h>
#include<graphics.h>
#include<dos.h>

void boundaryfill4(int x, int y, int fillcolor, int boundarycolor)
{
    if(getpixel(x, y) != boundarycolor && getpixel(x, y) != fillcolor)
    {
        delay(10);
        putpixel(x, y, fillcolor);
        boundaryfill4(x + 1, y, fillcolor, boundarycolor);
        boundaryfill4(x, y + 1, fillcolor, boundarycolor);
        boundaryfill4(x - 1, y, fillcolor, boundarycolor);
        boundaryfill4(x, y - 1, fillcolor, boundarycolor);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    circle(50, 50, 35);
    boundaryfill4(51, 51, 6, 15);
    //delay(1000);
    getch();
    closegraph();
    return 0;
}