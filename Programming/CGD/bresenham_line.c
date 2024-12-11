#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

void drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int p = 2 * dy - dx;
    int twoDy = 2 * dy;
    int twoDyDx = 2 * (dy - dx);
    int x, y, xEnd;

    if (x1 > x2) {
        x = x2;
        y = y2;
        xEnd = x1;
    } else {
        x = x1;
        y = y1;
        xEnd = x2;
    }

    putpixel(x, y, WHITE);

    while (x < xEnd) {
        x++;
        if (p < 0) {
            p += twoDy;
        } else {
            y++;
            p += twoDyDx;
        }
        putpixel(x, y, WHITE);
    }
}

void main() {
    int gdriver = DETECT, gmode;
    int x1, y1, x2, y2;
    initgraph(&gdriver, &gmode, "C:\\TC\\BGI");

    printf("Enter the starting point (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the ending point (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    drawLine(x1, y1, x2, y2);

    getch();
    closegraph();
}