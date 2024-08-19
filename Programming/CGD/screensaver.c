#include <conio.h>
#include <graphics.h>
#include <stdlib.h>

int main()
{
    int gd = DETECT, gm;
    int col = 480, row = 640, font = 4, direction = 2, size = 8, color = 15;

    initgraph(&gd, &gm, "C:\\TC\\BGI");
    cleardevice();

    while (!kbhit())
    {
        settextstyle(random(font), random(direction), random(size));
        setcolor(random(color));
        outtextxy(random(col), random(row), "Devansh");
        delay(250);
    }

    getch();
    return 0;
}