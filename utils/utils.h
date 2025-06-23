/**
 * @file utils.h
 * @brief File header cho các hàm tiện ích chung
 * @author Nguyen The Quan (24127514)
 * @date 2025
 * @version 1.0
 */

#ifndef UTILS_H
#define UTILS_H

/**
 * @brief Tính ước chung lớn nhất của hai số nguyên
 * @param a Số nguyên thứ nhất
 * @param b Số nguyên thứ hai
 * @return Ước chung lớn nhất của a và b
 * 
 * Sử dụng thuật toán Euclid để tính GCD.
 * Ví dụ: gcd(12, 8) = 4, gcd(15, 25) = 5
 */
int gcd (int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}



#endif // UTILS_H