#include "Input.h"
#include <iostream>
#include <regex>
#include "../Parser/Parser.h"

std::expected<std::string, InputError> Input::readValue(const std::string& regexPattern) {
    std::string input;
    std::getline(std::cin, input);

    // Empty
    if (input.empty()) {
        return std::unexpected(InputError::Empty);
    }

    // Check regex pattern
    if (!regexPattern.empty()) {
        std::regex pattern(regexPattern);
        if (!std::regex_match(input, pattern)) {
            return std::unexpected(InputError::NotANumber);
        }
    }


    return input;
}

std::expected<Vector<std::string>, InputError> Input::readMultipleValues(const char& delimiter, const std::string& regexPattern) {
    std::string input;
    std::getline(std::cin, input);

    // Empty
    if (input.empty()) {
        return std::unexpected(InputError::Empty);
    }

    Vector<std::string> values = Parser::parse(input, delimiter);

    for (int i = 0; i < values.size(); i++) {
        if (values[i].empty()) {
            return std::unexpected(InputError::Empty);
        }

        // Check regex pattern
        if (!regexPattern.empty()) {
            std::regex pattern(regexPattern);
            if (!std::regex_match(values[i], pattern)) {
                return std::unexpected(InputError::NotANumber);
            }
        }
    }

    return values;
}

std::expected<int, InputError> Input::readInt() {
    auto input = readValue(RegexPattern::INTEGER);
    if (!input.has_value()) {
        return std::unexpected(input.error());
    }
    return std::stoi(input.value());
}

std::expected<Vector<int>, InputError> Input:: readMultipleIntegers(const char& delimiter) {
    auto input = readMultipleValues(delimiter, RegexPattern::INTEGER);
    if (!input.has_value()) {
        return std::unexpected(input.error());
    }

    Vector<int> integers;
    for (int i = 0; i < input.value().size(); ++i) {
        integers.push_back(std::stoi(input.value()[i]));
    }

    return integers;
}

std::expected<double, InputError> Input::readDouble() {
    auto input = readValue(RegexPattern::DOUBLE);
    if (!input.has_value()) {
        return std::unexpected(input.error());
    }
    return std::stod(input.value());
}

std::expected<Vector<double>, InputError> Input::readMultipleDoubles(const char& delimiter) {
    auto input = readMultipleValues(delimiter, RegexPattern::DOUBLE);
    if (!input.has_value()) {
        return std::unexpected(input.error());
    }

    Vector<double> doubles;
    for (int i = 0; i < input.value().size(); ++i) {
        doubles.push_back(std::stod(input.value()[i]));
    }

    return doubles;
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
