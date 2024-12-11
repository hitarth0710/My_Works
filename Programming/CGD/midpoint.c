#include <graphics.h>
#include <conio.h>

void drawCircle(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

void midpointCircleDrawing(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int p = 1 - r;
    drawCircle(xc, yc, x, y);
    while (x < y) {
        x++;
        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y) + 1;
        }
        drawCircle(xc, yc, x, y);
    }
}

int main() {
    int gd = DETECT, gm;
    int xc, yc, r;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    xc = getmaxx() / 2; // X-coordinate of circle center
    yc = getmaxy() / 2; // Y-coordinate of circle center
    r = 200; // Increased radius of the circle
    setlinestyle(SOLID_LINE, 0, 3); // Increased pixel size to 3
    midpointCircleDrawing(xc, yc, r);
    getch();
    closegraph();
    return 0;
}