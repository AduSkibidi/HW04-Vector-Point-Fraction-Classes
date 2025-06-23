/**
 * @file Parser.h
 * @brief File header cho lớp Parser - phân tích chuỗi thành các thành phần
 * @author Nguyen The Quan (24127514)
 * @date 2025
 * @version 1.0
 */

#ifndef PARSER_H
#define PARSER_H

#include <string>
#include "../Vector/Vector.h"

/**
 * @class Parser
 * @brief Lớp tiện ích để phân tích chuỗi
 * 
 * Lớp Parser cung cấp:
 * - Tách chuỗi thành các phần dựa trên delimiter
 * - Xử lý các trường hợp đặc biệt
 * - Trả về kết quả dưới dạng Vector
 */
class Parser {
public:
    /**
     * @brief Phân tích chuỗi thành các phần tử dựa trên delimiter
     * @param input Chuỗi đầu vào cần phân tích
     * @param delimiter Ký tự phân cách (mặc định là khoảng trắng)
     * @return Vector chứa các phần tử đã được tách
     */
    static Vector<std::string> parse(const std::string& input, const char& delimiter = ' ');
};

#include "Parser.cpp"
#endif // PARSER_H