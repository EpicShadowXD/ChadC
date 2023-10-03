#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <regex>
#include <array>
#include <utility>
#include <string>

enum class Keywords {
    INT,
    FLOAT,
    CHAR,
    WHILE,
    IF,
    RETURN
};

enum class Operators {
    ASSIGNMENT,
    ADDITION,
    SUBTRACTION
};

enum class Separators {
    COMMA,
    SEMICOLON
};

enum class TokenType {
    Keyword,
    Operator,
    Separator,
    Identifier,
    Number,
    Unknown,
    Invalid
};

struct Token {
    TokenType type;
    std::string value;
};

const std::array<std::pair<std::string, TokenType>, 5> patterns = {
        std::make_pair<std::string, TokenType>("int|float|char|while|if|return", TokenType::Keyword),
        std::make_pair<std::string, TokenType>("[a-zA-Z_][a-zA-Z0-9_]*", TokenType::Identifier),
        std::make_pair<std::string, TokenType>("=|\\{|\\}|\\(|\\)", TokenType::Operator),
        std::make_pair<std::string, TokenType>("\\d+", TokenType::Number),
        std::make_pair<std::string, TokenType>(",|;", TokenType::Separator)
};