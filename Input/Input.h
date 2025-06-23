/**
 * @file Input.h
 * @brief File header cho lớp Input - xử lý nhập liệu từ bàn phím
 * @author Nguyen The Quan (24127514)
 * @date 2025
 * @version 1.0
 */

#ifndef INPUT_H
#define INPUT_H

#include <string>
#include <expected>
#include "../Vector/Vector.h"
#include "../RegexPattern/RegexPattern.h"

/**
 * @enum InputError
 * @brief Enum định nghĩa các loại lỗi nhập liệu
 */
enum class InputError {
    None,           ///< Không có lỗi
    Empty,          ///< Chuỗi rỗng
    NotANumber,     ///< Không phải số
    // OutOfRange   ///< Ngoài phạm vi (dành cho tương lai)
};

/**
 * @class Input
 * @brief Lớp tiện ích để xử lý nhập liệu từ bàn phím với validation
 * 
 * Lớp Input cung cấp:
 * - Đọc chuỗi với regex validation
 * - Đọc số nguyên và số thực
 * - Đọc nhiều giá trị với delimiter
 * - Xử lý lỗi bằng std::expected
 */
class Input {
public:
    /**
     * @brief Đọc giá trị chuỗi từ bàn phím với regex validation
     * @param regexPattern Pattern regex để kiểm tra định dạng
     * @return std::expected chứa chuỗi hoặc lỗi
     */
    static std::expected<std::string, InputError> readValue(const std::string& regexPattern = RegexPattern::STRING);
    
    /**
     * @brief Đọc nhiều giá trị từ bàn phím
     * @param delimiter Ký tự phân cách giữa các giá trị
     * @param regexPattern Pattern regex để kiểm tra từng giá trị
     * @return std::expected chứa Vector chuỗi hoặc lỗi
     */
    static std::expected<Vector<std::string>, InputError> readMultipleValues(const char& delimiter = ' ', const std::string& regexPattern = RegexPattern::STRING);
public:
    /**
     * @brief Đọc số nguyên từ bàn phím
     * @return std::expected chứa số nguyên hoặc lỗi
     */
    static std::expected<int, InputError> readInt();
    
    /**
     * @brief Đọc nhiều số nguyên từ bàn phím
     * @param delimiter Ký tự phân cách giữa các số
     * @return std::expected chứa Vector số nguyên hoặc lỗi
     */
    static std::expected<Vector<int>, InputError> readMultipleIntegers(const char& delimiter = ' ');
    
    /**
     * @brief Đọc số thực từ bàn phím
     * @return std::expected chứa số thực hoặc lỗi
     */
    static std::expected<double, InputError> readDouble();
    
    /**
     * @brief Đọc nhiều số thực từ bàn phím
     * @param delimiter Ký tự phân cách giữa các số
     * @return std::expected chứa Vector số thực hoặc lỗi
     */
    static std::expected<Vector<double>, InputError> readMultipleDoubles(const char& delimiter = ' ');
public:
    /**
     * @brief Lấy thông điệp lỗi từ mã lỗi
     * @param error Mã lỗi InputError
     * @return Chuỗi mô tả lỗi
     */
    static std::string getErrorMessage(InputError error);
};

#include "Input.cpp"
#endif // INPUT_H