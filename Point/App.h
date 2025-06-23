/**
 * @file App.h
 * @brief File header cho lớp App - ứng dụng xử lý các điểm 2D
 * @author Nguyen The Quan (24127514)
 * @date 2025
 * @version 1.0
 */

#ifndef APP_H
#define APP_H

#include "Point.h"
#include "../Vector/Vector.h"

/**
 * @class App
 * @brief Lớp ứng dụng chính để xử lý các thao tác với điểm 2D
 * 
 * Lớp App cung cấp các chức năng giao diện người dùng để:
 * - Nhập điểm từ bàn phím
 * - Nhập nhiều điểm
 * - Tính toán khoảng cách giữa các điểm
 * - Hiển thị báo cáo kết quả
 */
class App {
public:
	/**
	 * @brief Nhập điểm từ bàn phím cho đến khi hợp lệ
	 * @return Điểm Point đã được nhập và xác thực
	 */
	Point enterPointUntilValidUseCase();
	
	/**
	 * @brief Nhập nhiều điểm từ bàn phím
	 * @return Vector chứa các điểm Point đã nhập
	 */
	Vector<Point> enterMultiplePointsUseCase();
	
	/**
	 * @brief Tính tổng khoảng cách giữa các điểm liên tiếp
	 * @param points Vector chứa các điểm cần tính khoảng cách
	 * @return Tổng khoảng cách dưới dạng float
	 */
	float computePointsDistanceUseCase(const Vector<Point>& points);
	
	/**
	 * @brief In báo cáo tổng khoảng cách
	 * @param distance Tổng khoảng cách cần hiển thị
	 */
	void printTotalDistanceReportUseCase(float distance);
};


#include "App.cpp"
#endif // APP_H