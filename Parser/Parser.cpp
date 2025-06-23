#include "Parser.h"
#include <sstream>

Vector<std::string> Parser::parse(const std::string& input, const char& delimiter) {
    std::stringstream ss(input);
    Vector<std::string> tokens;
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

