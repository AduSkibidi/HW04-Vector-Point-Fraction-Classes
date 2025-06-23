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


#include "Line.cpp"
#endif // LINE_H