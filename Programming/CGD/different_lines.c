#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

int round_to_int(float x) {
    return (int)(x + 0.5);
}

void DDA(float x1, float y1, float x2, float y2, int linetype) {
    float dx, dy, steps, xincrement, yincrement;
    int k;
    float x = x1, y = y1;
    dx = x2 - x1;
    dy = y2 - y1;

    if (fabs(dx) > fabs(dy)) {
        steps = fabs(dx);
    } else {
        steps = fabs(dy);
    }

    xincrement = dx / steps;
    yincrement = dy / steps;

    putpixel(round_to_int(x), round_to_int(y), WHITE);

    for (k = 0; k < steps; k++) {
        if (linetype == 1) { // solid line
            putpixel(round_to_int(x), round_to_int(y), WHITE);
        } else if (linetype == 2) { // dashed line
            if (k % 12 < 6) {
                putpixel(round_to_int(x), round_to_int(y), WHITE);
            }
        } else if (linetype == 3) { // dotted line
            if (k % 8 == 0) {
                putpixel(round_to_int(x), round_to_int(y), WHITE);
            }
        }
        x += xincrement;
        y += yincrement;
    }
}

int main() {
    int gd = DETECT, gm;
    float x1, x2, y1, y2;

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    x1 = 150; y1 = 100; x2 = 150; y2 = 300;
    DDA(x1, y1, x2, y2, 1);

    x1 = 250; y1 = 100; x2 = 250; y2 = 300;
    DDA(x1, y1, x2, y2, 2);

    x1 = 350; y1 = 100; x2 = 350; y2 = 300;
    DDA(x1, y1, x2, y2, 3);

    getch();
    closegraph();
    return 0;
}