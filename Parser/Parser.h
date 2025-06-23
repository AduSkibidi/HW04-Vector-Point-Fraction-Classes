#ifndef PARSER_H
#define PARSER_H

#include <string>
#include "../Vector/Vector.h"

class Parser {
public:
    static Vector<std::string> parse(const std::string& input, const char& delimiter = ' ');
};

#include "Parser.cpp"
#endif // PARSER_H