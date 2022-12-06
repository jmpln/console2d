#ifndef DISPLAY_H
#define DISPLAY_H

#include "point2d.h"

#include <vector>

struct ConsoleSize
{
    static const int BORDER_SIZE = 1;
    static const int LINEFEED = 1;
    static const int OX_SIZE = 150;
    static const int OY_SIZE = 20;
    static const int SCREENWIDHT = OX_SIZE+BORDER_SIZE+LINEFEED;
    static const int SCREEHEIGHT = OY_SIZE+BORDER_SIZE+LINEFEED;
};
struct Display : ConsoleSize
{
    Display();
    char& operator () (int x, int y);
    void Draw(std::vector<Point2D> const &figure);
    void Show();
private:
    char screen[SCREEHEIGHT*SCREENWIDHT+1];
};

#endif
