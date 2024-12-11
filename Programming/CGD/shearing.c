#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    int x, y, x1, y1, x2, y2, x3, y3, shear_f;

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    printf("\nPlease enter first coordinate: ");
    scanf("%d %d", &x, &y);

    printf("\nPlease enter second coordinate: ");
    scanf("%d %d", &x1, &y1);

    printf("\nPlease enter third coordinate: ");
    scanf("%d %d", &x2, &y2);

    printf("\nPlease enter last coordinate: ");
    scanf("%d %d", &x3, &y3);

    printf("\nPlease enter shearing factor for x: ");
    scanf("%d", &shear_f);

    cleardevice();

    line(x, y, x1, y1);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x, y);

    setcolor(RED);

    x = x + y * shear_f;
    x1 = x1 + y1 * shear_f;
    x2 = x2 + y2 * shear_f;
    x3 = x3 + y3 * shear_f;

    line(x, y, x1, y1);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x, y);

    getch();
    closegraph();

    return 0;
}
