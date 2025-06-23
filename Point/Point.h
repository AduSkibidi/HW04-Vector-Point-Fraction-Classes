/**
 * @file Point.h
 * @brief File header cho lớp Point - biểu diễn một điểm 2D với tọa độ x, y
 * @author Nguyen The Quan (24127514)
 * @date 2025
 * @version 1.0
 */

#ifndef POINT_H
#define POINT_H

/**
 * @class Point
 * @brief Lớp biểu diễn một điểm 2D trong hệ tọa độ Descartes
 * 
 * Lớp Point cung cấp các chức năng để lưu trữ và thao tác với tọa độ 2D.
 * Hỗ trợ các thao tác cơ bản như lấy/đặt tọa độ và sử dụng một ký tự
 * phân cách có thể cấu hình cho việc biểu diễn chuỗi.
 */
class Point {
public:
    /**
     * @brief Ký tự phân cách mặc định cho việc biểu diễn điểm
     */
    static const char delimiter = ',';
private:
    /**
     * @brief Tọa độ x của điểm
     */
    double _x = 0.0;
    /**
     * @brief Tọa độ y của điểm
     */
    double _y = 0.0;
public:
    /**
     * @brief Constructor mặc định, khởi tạo điểm tại gốc tọa độ (0, 0)
     */
    Point();
    
    /**
     * @brief Constructor với tham số, khởi tạo điểm với tọa độ cho trước
     * @param x Tọa độ x
     * @param y Tọa độ y
     */
    Point(const double x, const double y);
    
    /**
     * @brief Destructor
     */
    ~Point();
public:
    /**
     * @brief Lấy tọa độ x
     * @return Giá trị tọa độ x
     */
    double getX() const;
    
    /**
     * @brief Lấy tọa độ y
     * @return Giá trị tọa độ y
     */
    double getY() const;
    
    /**
     * @brief Đặt tọa độ x
     * @param x Giá trị tọa độ x mới
     */
    void setX(const double x);
    
    /**
     * @brief Đặt tọa độ y
     * @param y Giá trị tọa độ y mới
     */
    void setY(const double y);
    
    /**
     * @brief Đặt cả hai tọa độ x và y
     * @param x Giá trị tọa độ x mới
     * @param y Giá trị tọa độ y mới
     */
    void setXY(const double x, const double y);
};

const char Point::delimiter;

#include "Point.cpp"
#endif // POINT_H
