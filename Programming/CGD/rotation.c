#include <graphics.h>
#include <stdio.h>
#include <math.h>

int main() {
    int gd = DETECT, gm;
    int pivot_x, pivot_y, x, y;
    double degree, radian;
    int rotated_point_x, rotated_point_y;

    initgraph(&gd, &gm, "C:\\TC\\BGI");
    cleardevice();

    printf("Enter the initial coordinates of the line: ");
    scanf("%d %d", &pivot_x, &pivot_y);

    printf("Enter the final coordinates of the line: ");
    scanf("%d %d", &x, &y);

    line(pivot_x, pivot_y, x, y);

    printf("Enter the rotation angle in degrees: ");
    scanf("%lf", &degree);

    radian = degree * (M_PI / 180.0);

    rotated_point_x = (int)(pivot_x + (x - pivot_x) * cos(radian) - (y - pivot_y) * sin(radian));
    rotated_point_y = (int)(pivot_y + (x - pivot_x) * sin(radian) + (y - pivot_y) * cos(radian));

    setcolor(RED);
    line(pivot_x, pivot_y, rotated_point_x, rotated_point_y);

    getch();
    closegraph();

    return 0;
}
