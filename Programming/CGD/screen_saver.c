#include <graphics.h>
#include <conio.h>
#include <dos.h>

void initializeGraphics() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
}

void closeGraphics() {
    closegraph();
}

int main() {
    int x = 50, y = 50;
    int xSpeed = 5, ySpeed = 5;
    int radius = 20;

    initializeGraphics();

    while (!kbhit()) {
        // Clear the screen
        cleardevice();

        // Draw the ball
        circle(x, y, radius);
        floodfill(x, y, WHITE);

        // Update ball position
        x += xSpeed;
        y += ySpeed;

        // Check for collision with screen boundaries
        if (x > getmaxx() - radius || x < radius) {
            xSpeed = -xSpeed;
        }
        if (y > getmaxy() - radius || y < radius) {
            ySpeed = -ySpeed;
        }

        // Delay for a short while to see the animation
        delay(30);
    }

    closeGraphics();
    return 0;
}