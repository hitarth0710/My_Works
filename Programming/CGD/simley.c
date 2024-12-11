#include <graphics.h>
#include <conio.h>

void drawSmiley(int x, int y) {
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(x, y, 50, 50);
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(x - 20, y - 20, 5, 10);
    fillellipse(x + 20, y - 20, 5, 10);
    arc(x, y + 10, 200, 340, 20);
}

int main() {
    int i;
    int gd = DETECT, gm;
    int x = 50, y = 200;

    initgraph(&gd, &gm, "C:\\TC\\BGI");
    for (i = 0; i < 10; i++) {
        cleardevice();
        drawSmiley(x, y);
        delay(500);
        x += 20;
    }
    getch();
    closegraph();
    return 0;
}