#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <regex>
#include <array>
#include <utility>
#include <string>

//void printTokens(const std::vector<Token>& tokens) {
//    for (const auto& token: tokens) {
//        std::cout << "Type: ";
//        if (token.type == TokenType::INT)
//            std::cout << "INT";
//        else if (token.type == TokenType::FLOAT)
//            std::cout << "FLOAT";
//        else if (token.type == TokenType::CHAR)
//            std::cout << "CHAR";
//        else if (token.type == TokenType::IDENTIFIER)
//            std::cout << "IDENTIFIER";
//        else if (token.type == TokenType::ASSIGN)
//            std::cout << "ASSIGN";
//        else if (token.type == TokenType::INT_VALUE)
//            std::cout << "INT_VALUE";
//        else if (token.type == TokenType::FLOAT_VALUE)
//            std::cout << "FLOAT_VALUE";
//        else if (token.type == TokenType::CHAR_VALUE)
//            std::cout << "CHAR_VALUE";
//        else if (token.type == TokenType::SEMICOLON)
//            std::cout << "SEMICOLON";
//        else std::cout << "INVALID";
//        std::cout << ", Value: " << token.value << std::endl;
//    }
//}

namespace V1 {

    enum class TokenType {
        INT,
        FLOAT,
        CHAR,
        IDENTIFIER,
        ASSIGN,
        /*
         // TODO: add operations
        ADD,
        SUBTRACT,
         */
        INT_VALUE,
        FLOAT_VALUE,
        CHAR_VALUE,
        SEMICOLON,
        INVALID
    };

    struct Token {
        TokenType type;
        std::string value;
    };

    std::vector<Token> tokenizer(std::string input) {
        std::istringstream iss(input);
        std::vector<Token> tokens;

        while (iss >> input) {
            // Types
            if (input == "int")
                tokens.push_back({ TokenType::INT, input });
            else if (input == "float")
                tokens.push_back({ TokenType::FLOAT, input });
            else if (input == "char")
                tokens.push_back({ TokenType::CHAR, input });
                // Identifier
            else if (std::regex_match(input, std::regex("^[a-zA-Z_][a-zA-Z0-9_]*$")))
                tokens.push_back({ TokenType::IDENTIFIER, input });
                // Assign
            else if (input == "=")
                tokens.push_back({ TokenType::ASSIGN, input });
                // Values
            else if ((std::regex_match(input, std::regex("^[+-]?[0-9]+$"))))
                tokens.push_back({TokenType::INT_VALUE, input});
            else if (std::regex_match(input, std::regex("^[-+]?[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?$")))
                tokens.push_back({TokenType::FLOAT_VALUE, input});
            else if (std::regex_match(input, std::regex("^'[^']*'$")))
                tokens.push_back({TokenType::CHAR_VALUE, });
                // Semicolon
            else if (input == ";")
                tokens.push_back({ TokenType::SEMICOLON, input });
            else
                tokens.push_back({TokenType::INVALID, input});
        }

        return tokens;
    }
}

namespace V2 {

    enum class Types {
        INT,
        FLOAT,
        CHAR
    };

    struct Value {
        Types type;
        std::string value;
    };

    enum class TypesOfOperations {
        ADD,
        SUBTRACT,
    };

    using Operation = std::pair<TypesOfOperations, int>;

    struct Expression : public Value {
        Operation operation; // operator precedence
        Value lvalue, rvalue; // TODO: add a result value too
    };

    Value calculator(Value lvalue, Value rvalue, TypesOfOperations operation) {
        Value output;
        output.type = lvalue.type;

        if (output.type == Types::INT)
        {
            if (operation == TypesOfOperations::ADD)
                output.value = std::to_string( stoi(lvalue.value) + stoi(rvalue.value) );
            else if (operation == TypesOfOperations::SUBTRACT)
                output.value = std::to_string( stoi(lvalue.value) - stoi(rvalue.value) );
        }
        else if (output.type == Types::FLOAT)
        {
            if (operation == TypesOfOperations::ADD)
                output.value = std::to_string( stof(lvalue.value) + stof(rvalue.value) );
            else if (operation == TypesOfOperations::SUBTRACT)
                output.value = std::to_string( stof(lvalue.value) - stof(rvalue.value) );
        }


        return output;
    }

    constexpr auto tokenizer2(const std::string& input) {
        std::vector<Expression> tokens;

        std::array<char, 2> operationCharacters{'+', '-'};
        for (const auto& operationCharacter : operationCharacters) {
            size_t operationPos = input.find(operationCharacter);

            if (operationPos != std::string::npos) {
                Value lvalue{Types::INT, input.substr(0, operationPos) };
                Value rvalue{Types::INT, input.substr(operationPos + 1) };
                Operation operation;

                if (input[operationPos] == '+')
                    operation = {TypesOfOperations::ADD, 4};
                else if (input[operationPos] == '-')
                    operation = {TypesOfOperations::SUBTRACT, 4};

                tokens.push_back(Expression{calculator(lvalue, rvalue, operation.first),
                                            operation,
                                            lvalue,
                                            rvalue});
            }
        }

        return tokens;
    }

}