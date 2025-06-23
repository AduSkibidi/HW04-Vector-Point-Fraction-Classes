/**
 * @file App.h
 * @brief File header cho lớp App - ứng dụng xử lý các phân số
 * @author Nguyen The Quan (24127514)
 * @date 2025
 * @version 1.0
 */

#ifndef APP_H
#define APP_H

#include "../Vector/Vector.h"
#include "../Input/Input.h"
#include "Fractions.h"
#include <iostream>
#include <format>

/**
 * @class App
 * @brief Lớp ứng dụng chính để xử lý các thao tác với phân số
 * 
 * Lớp App cung cấp các chức năng giao diện người dùng để:
 * - Nhập phân số từ bàn phím
 * - Nhập nhiều phân số
 * - Tính tổng các phân số
 * - Hiển thị báo cáo kết quả
 */
class App {
public:
	/**
	 * @brief Nhập phân số từ bàn phím cho đến khi hợp lệ
	 * @return Phân số Fraction đã được nhập và xác thực
	 */
	Fraction enterFractionUntilValidUseCase();
	
	/**
	 * @brief Nhập nhiều phân số từ bàn phím
	 * @return Vector chứa các phân số Fraction đã nhập
	 */
	Vector<Fraction> enterMultipleFractionsUseCase();
	
	/**
	 * @brief Tính tổng của các phân số
	 * @param fractions Vector chứa các phân số cần tính tổng
	 * @return Phân số Fraction là kết quả tổng
	 */
	Fraction computeFractionsSumUseCase(const Vector<Fraction>& fractions);
	
	/**
	 * @brief In báo cáo tổng phân số
	 * @param f Phân số kết quả cần hiển thị
	 */
	void printSumReportUseCase(const Fraction& f);
};

#include "App.cpp"
#endif