#ifndef INPUT_H
#define INPUT_H

#include <string>
#include <expected>
#include "../Vector/Vector.h"
#include "../RegexPattern/RegexPattern.h"

enum class InputError {
    None,
    Empty,
    NotANumber,
    // OutOfRange 
};

class Input {
public:
    static std::expected<std::string, InputError> readValue(const std::string& regexPattern = RegexPattern::STRING);
    static std::expected<Vector<std::string>, InputError> readMultipleValues(const char& delimiter = ' ', const std::string& regexPattern = RegexPattern::STRING);
public:
    static std::expected<int, InputError> readInt();
    static std::expected<Vector<int>, InputError> readMultipleIntegers(const char& delimiter = ' ');
    static std::expected<double, InputError> readDouble();
    static std::expected<Vector<double>, InputError> readMultipleDoubles(const char& delimiter = ' ');
public:
    static std::string getErrorMessage(InputError error);
};

#include "Input.cpp"
#endif // INPUT_H