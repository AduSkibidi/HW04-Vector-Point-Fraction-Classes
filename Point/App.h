#ifndef APP_H
#define APP_H

#include "Point.h"
#include "../Vector/Vector.h"

class App {
public:
	Point enterPointUntilValidUseCase();
	Vector<Point> enterMultiplePointsUseCase();
	float computePointsDistanceUseCase(const Vector<Point>& points);
	void printTotalDistanceReportUseCase(float distance);
};


#include "App.cpp"
#endif // APP_H