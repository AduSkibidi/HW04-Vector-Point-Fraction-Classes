#ifndef POINT_H
#define POINT_H

class Point {
public:
    static const char delimiter = ','; // Default delimiter for point representation
private:
    double _x = 0.0;
    double _y = 0.0;
public:
    Point();
    Point(const double x, const double y);
    ~Point();
public:
    double getX() const;
    double getY() const;
    void setX(const double x);
    void setY(const double y);
    void setXY(const double x, const double y);
};

const char Point::delimiter;

#include "Point.cpp"
#endif // POINT_H
