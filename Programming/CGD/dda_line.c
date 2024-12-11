#include <graphics.h>
#include <stdio.h>

int main()
{
    int gd = DETECT, gm;
    int x0, y0, x1, y1;
    float dx, dy, steps, x, y, k;
    int i;

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    printf("Enter the value of x0: ");
    scanf("%d", &x0);
    printf("Enter the value of y0: ");
    scanf("%d", &y0);
    printf("Enter the value of x1: ");
    scanf("%d", &x1);
    printf("Enter the value of y1: ");
    scanf("%d", &y1);

    dx = (float)(x1 - x0);
    dy = (float)(y1 - y0);

    if (dx >= dy)
    {
        steps = dx;
    }
    else
    {
        steps = dy;
    }

    dx = dx / steps;
    dy = dy / steps;
    x = x0;
    y = y0;

    for (i = 0; i <= steps; i++)
    {
        putpixel(x, y, WHITE);
        x += dx;
        y += dy;
    }

    getch();
    closegraph();
    return 0;
}