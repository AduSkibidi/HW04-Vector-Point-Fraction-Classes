#include "Point.h"


Point::Point() {
    _x = 0.0;
    _y = 0.0;
}

Point::Point(const double x, const double y) {
    _x = x;
    _y = y;
}

Point::~Point() {
    // Do nothing
}

double Point::getX() const {
    return _x;
}

double Point::getY() const {
    return _y;
}

void Point::setX(const double x) {
    _x = x;
}

void Point::setY(const double y) {
    _y = y;
}

void Point::setXY(const double x, const double y) {
    _x = x;
    _y = y;
}