#ifndef LINE_H
#define LINE_H

#include "../Point/Point.h"

class Line {
private:
    Point _start;
    Point _end;
public:
    Line();
    Line(const Point& start, const Point& end);
    ~Line();
public:
    double length() const;
};

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

#endif // LINE_H