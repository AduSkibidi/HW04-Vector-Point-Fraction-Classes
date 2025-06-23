/**
 * @file Line.h
 * @brief File header cho lớp Line - biểu diễn đoạn thẳng giữa hai điểm
 * @author Nguyen The Quan (24127514)
 * @date 2025
 * @version 1.0
 */

#ifndef LINE_H
#define LINE_H

#include "../Point/Point.h"

/**
 * @class Line
 * @brief Lớp biểu diễn đoạn thẳng được xác định bởi hai điểm
 * 
 * Lớp Line cung cấp:
 * - Lưu trữ điểm bắt đầu và điểm kết thúc
 * - Tính toán độ dài đoạn thẳng
 * - Các thao tác cơ bản với đoạn thẳng
 */
class Line {
private:
    /**
     * @brief Điểm bắt đầu của đoạn thẳng
     */
    Point _start;
    /**
     * @brief Điểm kết thúc của đoạn thẳng
     */
    Point _end;
public:
    /**
     * @brief Constructor mặc định, tạo đoạn thẳng từ (0,0) đến (0,0)
     */
    Line();
    
    /**
     * @brief Constructor với tham số
     * @param start Điểm bắt đầu
     * @param end Điểm kết thúc
     */
    Line(const Point& start, const Point& end);
    
    /**
     * @brief Destructor
     */
    ~Line();
public:
    /**
     * @brief Tính độ dài của đoạn thẳng
     * @return Độ dài đoạn thẳng dưới dạng double
     */
    double length() const;
};


#include "Line.cpp"
#endif // LINE_H