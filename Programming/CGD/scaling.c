#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void scale(int *x, int *y, float sx, float sy) {
    *x = *x * sx;
    *y = *y * sy;
}

int main() {
    int gd = DETECT, gm;
    
    int x1 = 100, y1 = 100;
    int x2 = 150, y2 = 50;
    int x3 = 200, y3 = 100;
    float sx = 1.5, sy = 1.5;
    initgraph(&gd, &gm, "C:\\TC\\BGI");


    drawTriangle(x1, y1, x2, y2, x3, y3);

    scale(&x1, &y1, sx, sy);
    scale(&x2, &y2, sx, sy);
    scale(&x3, &y3, sx, sy);

    drawTriangle(x1, y1, x2, y2, x3, y3);

    getch();
    closegraph();

    return 0;
}
