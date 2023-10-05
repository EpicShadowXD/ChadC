#pragma once

namespace TokenPatterns {
    const std::map <TokenTypeHierarchy::Types, std::string> types = {
            {TokenTypeHierarchy::Types::INT,   "int"},
            {TokenTypeHierarchy::Types::FLOAT, "float"},
            {TokenTypeHierarchy::Types::CHAR,  "char"}
    };

    const std::map <TokenTypeHierarchy::Keywords, std::string> keywords = {
            {TokenTypeHierarchy::Keywords::INT,    "int"},
            {TokenTypeHierarchy::Keywords::FLOAT,  "float"},
            {TokenTypeHierarchy::Keywords::CHAR,   "char"},
            {TokenTypeHierarchy::Keywords::WHILE,  "while"},
            {TokenTypeHierarchy::Keywords::IF,     "if"},
            {TokenTypeHierarchy::Keywords::RETURN, "return"}
    };

    const std::map <TokenTypeHierarchy::ArithmeticOperators, std::string> arithmeticOperators = {
            {TokenTypeHierarchy::ArithmeticOperators::ADD,      "+"},
            {TokenTypeHierarchy::ArithmeticOperators::SUB,      "-"},
            {TokenTypeHierarchy::ArithmeticOperators::MULTIPLY, "*"},
            {TokenTypeHierarchy::ArithmeticOperators::DIVIDE,   "/"}
    };

    const std::map <TokenTypeHierarchy::AssignmentOperators, std::string> assignmentOperators = {
            {TokenTypeHierarchy::AssignmentOperators::ASSIGN,   "="},
            {TokenTypeHierarchy::AssignmentOperators::ADD,      "+="},
            {TokenTypeHierarchy::AssignmentOperators::SUB,      "-="},
            {TokenTypeHierarchy::AssignmentOperators::MULTIPLY, "*="},
            {TokenTypeHierarchy::AssignmentOperators::DIVIDE,   "/="}
    };

    const std::map <TokenTypeHierarchy::Separators, std::string> separators = {
            {TokenTypeHierarchy::Separators::LParanthesis, "("},
            {TokenTypeHierarchy::Separators::RParanthesis, ")"},
            {TokenTypeHierarchy::Separators::LBracket,     "{"},
            {TokenTypeHierarchy::Separators::RBracket,     "}"},
            {TokenTypeHierarchy::Separators::Comma,        ","},
            {TokenTypeHierarchy::Separators::Semicolon,    ";"}
    };
}