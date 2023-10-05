#pragma once

namespace TokenTypeHierarchy {
    enum class Types {
        INT,
        FLOAT,
        CHAR,
    };

    enum class Keywords {
        INT,
        FLOAT,
        CHAR,
        WHILE,
        IF,
        RETURN
    };

    enum class ArithmeticOperators {
        ADD,
        SUB,
        MULTIPLY,
        DIVIDE
    };

    enum class AssignmentOperators {
        ASSIGN,
        ADD,
        SUB,
        MULTIPLY,
        DIVIDE
    };

    enum class Separators {
        LParanthesis,
        RParanthesis,
        LBracket,
        RBracket,
        Comma,
        Semicolon
    };

    struct Identifier {
        std::string name;
    };

    struct Number {
        int value;
    };
}