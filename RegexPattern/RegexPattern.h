#ifndef REGEXPATTERN_H
#define REGEXPATTERN_H

#include <string>

class RegexPattern {
public:
    // Pattern for integers (e.g., "123", "-456", "+789")
    static const std::string INTEGER;
    
    // Pattern for doubles (e.g., "123.45", "-67.89", "+12.3", "0.5")
    static const std::string DOUBLE;

    // Pattern for strings (e.g., "hello", "world", "C++")
    static const std::string STRING;
};

// Static member definitions
const std::string RegexPattern::INTEGER = R"(^[+-]?\d+$)";
const std::string RegexPattern::DOUBLE = R"(^[+-]?\d+(\.\d*)?$)";
const std::string RegexPattern::STRING = ".*"; // Matches any string, including empty strings

#endif // REGEXPATTERN_H