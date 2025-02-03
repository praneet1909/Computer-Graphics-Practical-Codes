#include <iostream>
#include <graphics.h>
#include <conio.h> // Added for _getch() function
using namespace std;

typedef unsigned int outcode;
enum { TOP = 0x1, BOTTOM = 0x2, RIGHT = 0x4, LEFT = 0x8 };

outcode CompOutCode(double x, double y, double xmin, double xmax, double ymin, double ymax);
void CSLCAD(double x0, double y0, double x1, double y1, double xmin, double xmax, double ymin, double ymax);

int main() {
    double xmin, xmax, ymin, ymax, x0, y0, x1, y1;
    initwindow(900, 800);

    cout << "Enter the bottom coordinates of the window: ";
    cin >> xmin;
    cout << "Enter the left coordinates of the window: ";
    cin >> ymin;
    cout << "Enter the right coordinates of the window: ";
    cin >> xmax;
    cout << "Enter the top coordinates of the window: ";
    cin >> ymax;

    rectangle(xmin, ymin, xmax, ymax);
    cout << "Enter the coordinates (Terminal Points) of the line: ";
    cin >> x0 >> y0 >> x1 >> y1;

    line(x0, y0, x1, y1);
    _getch(); // Wait for a key press
    cleardevice();

    CSLCAD(x0, y0, x1, y1, xmin, xmax, ymin, ymax);
    rectangle(xmin, ymin, xmax, ymax);
    _getch(); // Wait for a key press
    closegraph();
    return 0;
}

outcode CompOutCode(double x, double y, double xmin, double xmax, double ymin, double ymax) {
    outcode code = 0;
    if (y > ymax)
        code |= TOP;
    if (y < ymin)
        code |= BOTTOM;
    if (x > xmax)
        code |= RIGHT;
    if (x < xmin)
        code |= LEFT;
    return code;
}

void CSLCAD(double x0, double y0, double x1, double y1, double xmin, double xmax, double ymin, double ymax) {
    outcode outcode0, outcode1, outcodeout;
    bool accept = false, done = false;
    outcode0 = CompOutCode(x0, y0, xmin, xmax, ymin, ymax);
    outcode1 = CompOutCode(x1, y1, xmin, xmax, ymin, ymax);

    do {
        if (outcode0 == 0 && outcode1 == 0) {
            accept = true;
            done = true;
        }
        else if (outcode0 & outcode1) {
            done = true;
        }
        else {
            double x, y;
            int ocd = outcode0 ? outcode0 : outcode1;
            if (ocd & TOP) {
                x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
                y = ymax;
            }
            else if (ocd & BOTTOM) {
                x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
                y = ymin;
            }
            else if (ocd & LEFT) {
                y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
                x = xmin;
            }
            else {
                y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
                x = xmax;
            }
            if (ocd == outcode0) {
                x0 = x;
                y0 = y;
                outcode0 = CompOutCode(x0, y0, xmin, xmax, ymin, ymax);
            }
            else {
                x1 = x;
                y1 = y;
                outcode1 = CompOutCode(x1, y1, xmin, xmax, ymin, ymax);
            }
        }
    } while (done == false);

    if (accept == true) {
        line(x0, y0, x1, y1);
    }
}
