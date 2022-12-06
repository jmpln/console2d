#include "point2d.h"

Point2D::Point2D(int x, int y)
    : x_(x)
    , y_(y)
{}
int Point2D::X() const { return x_; }
int Point2D::Y() const { return y_; }

