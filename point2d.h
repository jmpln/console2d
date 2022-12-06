#ifndef POINT2D_H
#define POINT2D_H

struct Point2D
{
    Point2D(int=0,int=0);

    int X() const;
    int Y() const;
private:
    int x_;
    int y_;
};

#endif

