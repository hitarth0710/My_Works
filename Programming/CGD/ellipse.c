#include <stdio.h>
#include <graphics.h>

void drawEllipse(int xc, int yc, int rx, int ry);

int main() {
    int gd = DETECT, gm;
    int xc, yc, rx, ry;

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    printf("Enter the center coordinates (xc, yc): ");
    scanf("%d%d", &xc, &yc);

    printf("Enter the x-radius and y-radius (rx, ry): ");
    scanf("%d%d", &rx, &ry);

    drawEllipse(xc, yc, rx, ry);

    getch();
    closegraph();

    return 0;
}

void drawEllipse(int xc, int yc, int rx, int ry) {
    int x = 0, y = ry;
    int rxSq = rx * rx;
    int rySq = ry * ry;
    int twoRxSq = 2 * rxSq;
    int twoRySq = 2 * rySq;
    int p;
    int px = 0, py = twoRxSq * y;

    p = rySq - (rxSq * ry) + (0.25 * rxSq);

    while (px < py) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        x++;
        px += twoRySq;

        if (p < 0) {
            p += rySq + px;
        } else {
            y--;
            py -= twoRxSq;
            p += rySq + px - py;
        }
    }

    p = rySq * (x + 0.5) * (x + 0.5) + rxSq * (y - 1) * (y - 1) - rxSq * rySq;

    while (y > 0) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        y--;
        py -= twoRxSq;

        if (p > 0) {
            p += rxSq - py;
        } else {
            x++;
            px += twoRySq;
            p += rxSq - py + px;
        }
    }
}
