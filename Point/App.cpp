#include <iostream>
#include <format>
#include "App.h"
#include "../Input/Input.h"
#include "../Line/Line.h"

Point App::enterPointUntilValidUseCase() {
   Point point;
   while (true) {
        std::cout << "Nhập tọa độ x, y (ví dụ: 1.0,2.0): ";
        auto pointInput = Input::readMultipleDoubles(Point::delimiter);
        if (!pointInput.has_value()) {
            std::cout << std::format("Lỗi: {}. Vui lòng nhập lại.\n", Input::getErrorMessage(pointInput.error()));
        } 
        else {
            if (pointInput.value().size() < 2) {
                std::cout << "Vui lòng nhập cả hai tọa độ x và y.\n";
                continue;
            } 
            else {
                point.setXY(pointInput.value()[0], pointInput.value()[1]);
                break; // Thoát khỏi vòng lặp nếu nhập thành công
            } 
        }
    }

    return point;
}

Vector<Point> App::enterMultiplePointsUseCase() {
    Vector<Point> points;
    int numberOfPoints;
    while (true) {
        std::cout << "Nhập số lượng điểm: ";
        auto numberInput = Input::readInt();
        if (!numberInput.has_value()) {
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

    std::cout << std::format("Đã nhập thành công {} điểm.\n", numberOfPoints);
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
