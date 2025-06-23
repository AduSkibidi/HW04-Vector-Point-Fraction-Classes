#include "App.h"

int main() {
    std::cout << "Chương trình tính tổng khoảng cách giữa các điểm trong mặt phẳng.\n";
    std::cout << "Bạn sẽ nhập các điểm theo thứ tự từ điểm đầu tiên đến điểm cuối cùng.\n";

    App app;
	Vector<Point> points = app.enterMultiplePointsUseCase();
	float totalDistance = app.computePointsDistanceUseCase(points);
	app.printTotalDistanceReportUseCase(totalDistance);

    std::cout << "Cảm ơn bạn đã sử dụng chương trình!\n";
    std::cout << "Hẹn gặp lại!\n";
    std::cout << "Nhấn Enter để thoát chương trình...";
    std::cin.get();
    return 0;
}