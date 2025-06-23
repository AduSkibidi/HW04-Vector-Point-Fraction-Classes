/**
 * @file RegexPattern.h
 * @brief File header cho lớp RegexPattern - chứa các pattern regex thông dụng
 * @author Nguyen The Quan (24127514)
 * @date 2025
 * @version 1.0
 */

#ifndef REGEXPATTERN_H
#define REGEXPATTERN_H

#include <string>

/**
 * @class RegexPattern
 * @brief Lớp chứa các pattern regex được định nghĩa sẵn
 * 
 * Lớp RegexPattern cung cấp:
 * - Pattern cho số nguyên
 * - Pattern cho số thực
 * - Pattern cho chuỗi
 * - Các pattern validation khác
 */
class RegexPattern {
public:
    /**
     * @brief Pattern cho số nguyên (ví dụ: "123", "-456", "+789")
     */
    static const std::string INTEGER;
    
    /**
     * @brief Pattern cho số thực (ví dụ: "123.45", "-67.89", "+12.3", "0.5")
     */
    static const std::string DOUBLE;

    /**
     * @brief Pattern cho chuỗi (ví dụ: "hello", "world", "C++")
     */
    static const std::string STRING;
};

// Định nghĩa static members
const std::string RegexPattern::INTEGER = R"(^[+-]?\d+$)";
const std::string RegexPattern::DOUBLE = R"(^[+-]?\d+(\.\d*)?$)";
const std::string RegexPattern::STRING = ".*"; // Khớp với bất kỳ chuỗi nào, bao gồm chuỗi rỗng

#endif // REGEXPATTERN_H