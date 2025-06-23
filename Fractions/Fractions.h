/**
 * @file Fractions.h
 * @brief File header cho lớp Fraction - biểu diễn phân số với tử số và mẫu số
 * @author Nguyen The Quan (24127514)
 * @date 2025
 * @version 1.0
 */

#ifndef FRACTIONS_H
#define FRACTIONS_H

/**
 * @class Fraction
 * @brief Lớp biểu diễn phân số với các phép toán cơ bản
 * 
 * Lớp Fraction cung cấp:
 * - Lưu trữ tử số và mẫu số
 * - Rút gọn phân số tự động
 * - Các phép toán cộng, trừ, nhân
 * - Chuyển đổi sang chuỗi
 */
class Fraction {
public:
    /**
     * @brief Ký tự phân cách mặc định cho việc biểu diễn phân số
     */
    static const char delimiter = '/';
private:
    /**
     * @brief Tử số của phân số
     */
    int _numerator = 0;
    /**
     * @brief Mẫu số của phân số
     */
    int _denominator = 1;
    /**
     * @brief Rút gọn phân số về dạng tối giản
     */
    void _reduce();
public:
    /**
     * @brief Constructor mặc định, khởi tạo phân số 0/1
     */
    Fraction();
    
    /**
     * @brief Constructor với tham số
     * @param numerator Tử số
     * @param denominator Mẫu số (khác 0)
     */
    Fraction(int numerator, int denominator);
    
    /**
     * @brief Destructor
     */
    ~Fraction();
public:
    /**
     * @brief Lấy tử số
     * @return Giá trị tử số
     */
    int getNumerator() const;
    
    /**
     * @brief Lấy mẫu số
     * @return Giá trị mẫu số
     */
    int getDenominator() const;
    
    /**
     * @brief Đặt tử số
     * @param numerator Giá trị tử số mới
     */
    void setNumerator(int numerator);
    
    /**
     * @brief Đặt mẫu số
     * @param denominator Giá trị mẫu số mới (khác 0)
     */
    void setDenominator(int denominator);
    
    /**
     * @brief Đặt cả tử số và mẫu số
     * @param numerator Giá trị tử số mới
     * @param denominator Giá trị mẫu số mới (khác 0)
     */
    void setFraction(int numerator, int denominator);
public:
    /**
     * @brief Toán tử cộng phân số
     * @param other Phân số cần cộng
     * @return Kết quả phân số sau khi cộng
     */
    Fraction operator+(const Fraction& other) const;
    
    /**
     * @brief Toán tử trừ phân số
     * @param other Phân số cần trừ
     * @return Kết quả phân số sau khi trừ
     */
    Fraction operator-(const Fraction& other) const;
    
    /**
     * @brief Toán tử nhân phân số
     * @param other Phân số cần nhân
     * @return Kết quả phân số sau khi nhân
     */
    Fraction operator*(const Fraction& other) const;
public:
    /**
     * @brief Chuyển đổi phân số sang chuỗi
     * @return Chuỗi biểu diễn phân số dạng "tử/mẫu"
     */
    std::string toString() const;
};


#include "Fractions.cpp"
#endif // FRACTIONS_H