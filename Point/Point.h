#ifndef POINT_H
#define POINT_H

class Point {
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
#endif // POINT_H
