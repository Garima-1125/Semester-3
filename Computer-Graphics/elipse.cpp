#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;

void plotPoints(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}

void drawEllipse(int xc, int yc, int rx, int ry) {
    int x = 0;
    int y = ry;

    long rx2 = rx * rx;
    long ry2 = ry * ry;
    long twoRx2 = 2 * rx2;
    long twoRy2 = 2 * ry2;

    long px = 0;
    long py = twoRx2 * y;

    // Region 1
    long p1 = ry2 - (rx2 * ry) + (rx2 / 4);

    while (px < py) {
        plotPoints(xc, yc, x, y);
        x++;
        px += twoRy2;

        if (p1 < 0) {
            p1 += ry2 + px;
        } else {
            y--;
            py -= twoRx2;
            p1 += ry2 + px - py;
        }
    }

    // Region 2
    long p2 = (ry2 * (x + 0.5) * (x + 0.5)) +
              (rx2 * (y - 1) * (y - 1)) -
              (rx2 * ry2);

    while (y >= 0) {
        plotPoints(xc, yc, x, y);
        y--;
        py -= twoRx2;

        if (p2 > 0) {
            p2 += rx2 - py;
        } else {
            x++;
            px += twoRy2;
            p2 += rx2 - py + px;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc, yc, rx, ry;
    cout << "Enter center (xc yc): ";
    cin >> xc >> yc;
    cout << "Enter rx and ry: ";
    cin >> rx >> ry;

    drawEllipse(xc, yc, rx, ry);

    getch();
    closegraph();
    return 0;
}

