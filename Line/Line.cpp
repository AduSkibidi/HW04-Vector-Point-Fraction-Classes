#include "Line.h"
#include <cmath>

Line::Line() {
    _start = Point(0.0, 0.0);
    _end = Point(0.0, 0.0);
}

Line::Line(const Point& start, const Point& end) {
    _start = start;
    _end = end;
}

Line::~Line() {
    // Do nothing
}

double Line::length() const {
    double dx = _end.getX() - _start.getX();
    double dy = _end.getY() - _start.getY();
    return std::sqrt(dx * dx + dy * dy);
}