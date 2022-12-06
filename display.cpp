#include "display.h"

#include <iostream>

Display::Display()
{
    for (int x, y = 0; y < SCREEHEIGHT; ++y) {
        for (x = 0; x < SCREENWIDHT; ++x) {
            if (x == SCREENWIDHT-1) {
                screen[y*SCREENWIDHT+x] = '\n';
            }
            else if (
                x < BORDER_SIZE
                || y < BORDER_SIZE
                || SCREENWIDHT-LINEFEED-x-1 < BORDER_SIZE
                || SCREEHEIGHT-y-1          < BORDER_SIZE
            ) {
                screen[y*SCREENWIDHT+x] = '#';
            }
            else {
                screen[y*SCREENWIDHT+x] = ' ';
            }
        }
    }
    screen[SCREENWIDHT*SCREEHEIGHT] = 0;
}
char& Display::operator () (int x, int y)
{
    return screen[(y+BORDER_SIZE)*SCREENWIDHT + (x+BORDER_SIZE)];
}
void Display::Show()
{
    std::cout.write(screen, SCREENWIDHT*SCREEHEIGHT);
}
void Display::Draw(std::vector<Point2D> const &figure)
{
    int maxX, minX, maxY, minY,
        x, y, x1, x2, y1, y2;

    for (auto pIt1 = figure.begin(),
              pIt2 = pIt1 + 1,
              pEnd = figure.end(); pIt1 != pEnd; ++pIt1, ++pIt2) {
        if (pIt2 == pEnd) {
            pIt2 = figure.begin();
        }
        x1 = pIt1->X();
        x2 = pIt2->X();
        y1 = pIt1->Y();
        y2 = pIt2->Y();

        maxX = std::max(x1, x2);
        minX = std::min(x1, x2);
        maxY = std::max(y1, y2);
        minY = std::min(y1, y2);

        for (y = minY; y <= maxY; ++y) {
            for (x = minX; x <= maxX; ++x) {
                if ((x-x1)*(y2-y1) == (y-y1)*(x2-x1)){
                    (*this)(x, y) = '@';
                }
            }
        }
    }
}


