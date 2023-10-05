#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <regex>
#include <array>
#include <utility>
#include <string>
#include <map>
#include <variant>

enum class TokenType {
    Keyword,
    Operator, /*
    LParanthesis,
    RParanthesis,
    LBracket,
    RBracket, */
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

namespace operators {
    enum class Arithmetic {
        ADD,
        SUB,
        MULTIPLY,
        DIVIDE
    };

    const std::map<Arithmetic, std::string> arithmetics = {
            {Arithmetic::ADD, "+"},
            {Arithmetic::SUB, "-"},
            {Arithmetic::MULTIPLY, "*"},
            {Arithmetic::DIVIDE, "/"},
    };

    enum class Assignment {
        ASSIGN,
        ADD,
        SUB,
        MULTIPLY,
        DIVIDE
    };

    const std::map<Assignment, std::string> assignments = {
        {Assignment::ASSIGN, "="},
        {Assignment::ADD, "+="},
        {Assignment::SUB, "-="},
        {Assignment::MULTIPLY, "*="},
        {Assignment::DIVIDE, "/="},
    };
};

namespace separators {
    enum class Separators {
        LParanthesis,
        RParanthesis,
        LBracket,
        RBracket,
        Comma,
        Semicolon
    };

    const std::map<Separators, std::string> separators = {
        {Separators::LParanthesis, "("},
        {Separators::RParanthesis, ")"},
        {Separators::LBracket, "{"},
        {Separators::RBracket, "}"},
        {Separators::Comma, ";"},
        {Separators::Semicolon, ";"},
    };
}

template <typename MapType>
std::string buildSingleOperator(const std::map<MapType, std::string>& things) {
    std::string output;

    for (const auto& thing : things) {
        if (!output.empty())
            output += "|";
        output += "\\" + std::get<1>(thing);
    }

    return output;
}

template <typename MapType>
std::string buildPattern(const std::vector<std::map<MapType, std::string>>& maps) {
    std::string pattern("(");

    for (const auto& map : maps)
        pattern += buildSingleOperator(map);

    return (pattern += ")");
}

// type as TokenType, regex pattern as std::string, type as std::string
const std::map<TokenType, std::tuple<std::string, std::string>> patterns({
        {TokenType::Keyword, std::make_pair("int|float|char|while|if|return", "Keyword")},
        {TokenType::Identifier, std::make_pair("[a-zA-Z_][a-zA-Z0-9_]*", "Identifier")},
        {TokenType::Operator, std::make_pair("(" + buildSingleOperator(operators::arithmetics) + buildSingleOperator(operators::assignments) + ")", "Operator")}, // "=|\\{|\\}|\\(|\\)|;|\\+\\+|--"
        {TokenType::Separator, std::make_pair("(" + buildSingleOperator(separators::separators) + ")", "Separator")},
        {TokenType::Number, std::make_pair("\\d+", "Number")}
});