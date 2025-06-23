#ifndef INPUT_H
#define INPUT_H

#include <string>
#include <expected>

enum class InputError {
    None,
    Empty,
    NotANumber,
    // OutOfRange Trong bài này không cần sử dụng
};

class Input {
public:
    static std::expected<std::string, InputError> readValue();
public:
    static std::expected<int, InputError> readInt();
    static std::expected<double, InputError> readDouble();
public:
    static std::string getErrorMessage(InputError error);
};


#include <iostream>
#include <regex>

std::expected<std::string, InputError> Input::readValue() {
    std::string input;
    std::getline(std::cin, input);

    // Empty
    if (input.empty()) {
        return std::unexpected(InputError::Empty);
    }

    // Is a number
    std::regex numberRegex("^-?\\d+(\\.\\d+)?$");
    if (!std::regex_match(input, numberRegex)) {
        return std::unexpected(InputError::NotANumber);
    }


    return input;
}

std::expected<int, InputError> Input::readInt() {
    auto input = readValue();
    if (!input.has_value()) {
        return std::unexpected(input.error());
    }
    return std::stoi(input.value());
}

std::expected<double, InputError> Input::readDouble() {
    auto input = readValue();
    if (!input.has_value()) {
        return std::unexpected(input.error());
    }
    return std::stod(input.value());
}

std::string Input::getErrorMessage(InputError error) {
    switch (error) {
        case InputError::None:
            return "None";
        case InputError::Empty:
            return "Dữ liệu nhập rỗng";
        case InputError::NotANumber:
            return "Dữ liệu nhập vào không phải là một số hợp lệ";
        // case InputError::OutOfRange: // Trong bài này không cần sử dụng
        //     return "Giá trị nằm ngoài phạm vi cho phép";
        default:
            return "Lỗi không xác định";
    }
}

#endif // INPUT_H