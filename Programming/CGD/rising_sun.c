#include <graphics.h>
#include <conio.h>
#include <dos.h>

void drawSun(int x, int y, int radius) {
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(x, y, radius, radius);
}

int main() {
    int i;
    int gd = DETECT, gm;
    int sunY = 400;
    int radius = 30;
    
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    
    for (i = 0; i < 300; i++) {
        cleardevice();
        
        setcolor(LIGHTBLUE);
        setfillstyle(SOLID_FILL, LIGHTBLUE);
        bar(0, 0, getmaxx(), getmaxy());
        
        setcolor(GREEN);
        setfillstyle(SOLID_FILL, GREEN);
        bar(0, 400, getmaxx(), getmaxy());
        
        drawSun(320, sunY - i, radius);
        delay(30);
    }
    
    getch();
    closegraph();
    return 0;
}