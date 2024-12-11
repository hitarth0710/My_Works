#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void main()
{
    int gdriver = DETECT, gmode, err;
    int i, maxx, midy;
    initgraph(&gdriver, &gmode, "C://TC//BGI");
    err = graphresult();
    maxx = getmaxx();
    midy = getmaxy() / 2;

    for (i = 0; i < maxx - 125; i = i + 3) {
        cleardevice();
        setcolor(WHITE);
        line(0, midy + 37, maxx, midy + 37);
        setcolor(RED);
        setfillstyle(SOLID_FILL, YELLOW);
        line(0 + i, midy + 23, 0 + i, midy);
        line(0 + i, midy, 20 + i, midy);
        line(20 + i, midy, 40 + i, midy - 20);
        line(40 + i, midy - 20, 80 + i, midy - 20);
        line(80 + i, midy - 20, 100 + i, midy);
        line(100 + i, midy, 120 + i, midy);
        line(120 + i, midy, 120 + i, midy + 23);
        line(0 + i, midy + 23, 18 + i, midy + 23);
        arc(30 + i, midy + 23, 0, 180, 12);
        line(42 + i, midy + 23, 78 + i, midy + 23);
        arc(90 + i, midy + 23, 0, 180, 12);
        line(28 + i, midy, 43 + i, midy - 15);
        line(43 + i, midy - 15, 57 + i, midy - 15);
        line(57 + i, midy - 15, 57 + i, midy);
        line(57 + i, midy, 28 + i, midy);
        line(62 + i, midy - 15, 77 + i, midy - 15);
        line(77 + i, midy - 15, 92 + i, midy);
        line(92 + i, midy, 62 + i, midy);
        line(62 + i, midy, 62 + i, midy - 15);
        floodfill(5 + i, midy + 22, RED);
        setcolor(DARKGRAY);

        if (i % 2 == 0) {
            setfillstyle(SLASH_FILL, DARKGRAY);
        } else {
            setfillstyle(BKSLASH_FILL, DARKGRAY);
        }

        circle(30 + i, midy + 25, 9);
        circle(90 + i, midy + 25, 9);
        floodfill(30 + i, midy + 25, DARKGRAY);
        floodfill(90 + i, midy + 25, DARKGRAY);
        delay(250);
    }

    getch();
    closegraph();
}