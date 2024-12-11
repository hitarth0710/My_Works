#include <conio.h>
#include <graphics.h>
#include <dos.h>

void floodfill4(int x, int y, int fillcolor, int oldcolor) {
    if (getpixel(x, y) == oldcolor) {
        delay(1);
        putpixel(x, y, fillcolor);
        floodfill4(x + 1, y, fillcolor, oldcolor);
        floodfill4(x - 1, y, fillcolor, oldcolor);
        floodfill4(x, y + 1, fillcolor, oldcolor);
        floodfill4(x, y - 1, fillcolor, oldcolor);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    rectangle(50, 50, 100, 100);
    floodfill4(51, 51, 13, 0);
    getch();
    closegraph();
    return 0;
}