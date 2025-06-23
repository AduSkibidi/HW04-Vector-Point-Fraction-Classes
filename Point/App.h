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

#include <iostream>
#include <format>
#include "../Input/Input.h"
#include "../Line/Line.h"

Point App::enterPointUntilValidUseCase() {
    double x;
    while (true) {
        std::cout << "x = ";
        auto xInput = Input::readDouble();
        if (!xInput.has_value()) {
           std::cout << std::format("{}. Vui lòng nhập lại.\n", Input::getErrorMessage(xInput.error()));
        } else {
            x = xInput.value();
          break;
        }
    }
    double y;
    while (true) {
        std::cout << "y = ";
        auto yInput = Input::readDouble();
        if (!yInput.has_value()) {
           std::cout << std::format("Lỗi: {}. Vui lòng nhập lại.\n", Input::getErrorMessage(yInput.error()));
        } else {
            y = yInput.value();
          break;
        }
    }

    Point point;
    point.setXY(x, y);
    return point;
}

Vector<Point> App::enterMultiplePointsUseCase() {
    Vector<Point> points;
    int numberOfPoints;
    while (true) {
        std::cout << "Nhập số lượng điểm (>= 2): ";
        auto numberInput = Input::readInt();
        if (!numberInput.has_value() || numberInput.value() < 2) {
            std::cout << std::format("Lỗi: {}. Vui lòng nhập lại.\n", Input::getErrorMessage(numberInput.error()));
        } else {
            numberOfPoints = numberInput.value();
            break;
        }
    }

    for (int i = 0; i < numberOfPoints; ++i) {
        std::cout << std::format("Nhập điểm thứ {}:\n", i + 1);
        Point point = enterPointUntilValidUseCase();
        points.push_back(point);
        std::cout << std::format("Nhập thành công điểm thứ {}: ({:.2f}, {:.2f})\n", i + 1, point.getX(), point.getY());
    }

    return points;
}

float App::computePointsDistanceUseCase(const Vector<Point>& points) {
    float totalDistance = 0;
    for (int i = 0; i < points.size() - 1; i++) {
        Line line(points[i], points[i + 1]);
        totalDistance += line.length();
    }

    return totalDistance;
}

void App::printTotalDistanceReportUseCase(float distance) {
    std::string header = "REPORT OF TOTAL DISTANCE";
    std::string footer = "END OF REPORT";
    size_t padding = 4; // Padding for the borders
    size_t maxWidth = std::max(header.size(), footer.size()) + padding * 2;

    std::cout << std::format("|{}|", std::string(maxWidth - 2, '=')) << "\n";
    std::cout << std::format("|{:^{}s}|", header, maxWidth - 2) << "\n";
    std::cout << std::format("|{}|", std::string(maxWidth - 2, '-')) << "\n";
    std::cout << std::format("|{:^{}s}|", std::format("Total distance: {:.2f}", distance), maxWidth - 2) << "\n";
    std::cout << std::format("|{}|", std::string(maxWidth - 2, '-')) << "\n";
    std::cout << std::format("|{:^{}s}|", footer, maxWidth - 2) << "\n";
    std::cout << std::format("|{}|", std::string(maxWidth - 2, '=')) << "\n";

}


#endif // APP_H