#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void drawAxes() {
    int maxX = getmaxx();
    int maxY = getmaxy();
    line(0, maxY / 2, maxX, maxY / 2);
    line(maxX / 2, 0, maxX / 2, maxY);
}

int main() {
    int gd = DETECT, gm;
    int x1 = 100, y1 = 100;
    int x2 = 150, y2 = 50;
    int x3 = 200, y3 = 100;
    initgraph(&gd, &gm, "C:\\TC\\BGI");



    drawAxes();

    drawTriangle(x1, y1, x2, y2, x3, y3);
    drawTriangle(x1, getmaxy() - y1, x2, getmaxy() - y2, x3, getmaxy() - y3);
    drawTriangle(getmaxx() - x1, y1, getmaxx() - x2, y2, getmaxx() - x3, y3);
    drawTriangle(getmaxx() - x1, getmaxy() - y1, getmaxx() - x2, getmaxy() - y2, getmaxx() - x3, getmaxy() - y3);

    getch();
    closegraph();

    return 0;
}
