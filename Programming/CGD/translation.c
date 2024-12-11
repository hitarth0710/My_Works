#include <graphics.h>
#include <conio.h>

void translateLine(int P[2][2], int T[]) {
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    setcolor(2);
    line(P[0][0], P[0][1], P[1][0], P[1][1]);

    P[0][0] = P[0][0] + T[0];
    P[0][1] = P[0][1] + T[1];
    P[1][0] = P[1][0] + T[0];
    P[1][1] = P[1][1] + T[1];

    setcolor(3);
    line(P[0][0], P[0][1], P[1][0], P[1][1]);

    getch();
    closegraph();
}

int main() {
    int P[2][2] = { {100, 150}, {200, 250} };
    int T[] = {50, 30};

    translateLine(P, T);

    return 0;
}
