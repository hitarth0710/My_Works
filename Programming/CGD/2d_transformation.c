#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

int main() {
    double a;
    int gd = DETECT, gm, ch;
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
    printf("1.Translation\n2.Rotation\n3.Scaling\n4.Reflection\n5.Shearing\n");
    printf("\n Enter choice: ");
    scanf("%d", &ch);

    switch (ch) {
        case 1: {
            int x1 = 200, y1 = 150, x2 = 300, y2 = 250;
            int tx = 50, ty = 50;
            printf("Rectangle before translation\n");
            setcolor(2); // cyan
            rectangle(x1, y1, x2, y2);
            printf("Rectangle after translation\n");
            setcolor(4); // red
            rectangle(x1 + tx, y1 + ty, x2 + tx, y2 + ty);
            getch();
            break;
        }
        case 2: {
            setcolor(6);
            long x1 = 200, y1 = 200, x2 = 300, y2 = 300, xr, yr;
            printf("Rectangle with rotation\n");
            rectangle(x1, y1, x2, y2);
            printf("Angle of rotation: ");
            scanf("%lf", &a);
            a = (a * 3.14) / 180;
            xr = x1 + ((x2 - x1) * cos(a) - (y2 - y1) * sin(a));
            yr = y1 + ((x2 - x1) * sin(a) + (y2 - y1) * cos(a));
            setcolor(7); // green
            rectangle(x1, y1, xr, yr);
            getch();
            break;
        }
        case 3: {
            int x1 = 100, y1 = 100, x2 = 200, y2 = 200, x = 2, y = 2;
            printf("Before scaling\n");
            setcolor(4);
            rectangle(x1, y1, x2, y2);
            printf("After scaling\n");
            setcolor(12); // light green
            rectangle(x1 * x, y1 * y, x2 * x, y2 * y);
            getch();
            break;
        }
        case 4: {
            int x1 = 200, y1 = 300, x2 = 500, y2 = 300, x3 = 350, y3 = 400;
            printf("Triangle before reflection\n");
            setcolor(5);
            line(x1, y1, x2, y2);
            line(x1, y1, x3, y3);
            line(x2, y2, x3, y3);
            printf("Triangle after reflection\n");
            setcolor(3);
            line(x1, -y1 + 500, x2, -y2 + 500);
            line(x1, -y1 + 500, x3, -y3 + 500);
            line(x2, -y2 + 500, x3, -y3 + 500);
            getch();
            break;
        }
        case 5: {
            int x1 = 100, y1 = 100, x2 = 150, y2 = 200, x3 = 200, y3 = 100;
            int shx = 2;
            printf("Before shearing of triangle\n");
            setcolor(8);
            line(x1, y1, x2, y2);
            line(x2, y2, x3, y3);
            line(x3, y3, x1, y1);
            printf("After shearing of triangle\n");
            x1 = x1 + shx * y1;
            x2 = x2 + shx * y2;
            x3 = x3 + shx * y3;
            setcolor(10);
            line(x1, y1, x2, y2);
            line(x2, y2, x3, y3);
            line(x3, y3, x1, y1);
            getch();
            break;
        }
        default:
            printf("Invalid choice\n");
            break;
    }

    closegraph();
    return 0;
}