#pragma once

#include <string>
#include <string_view>
#include <stdexcept>
#include <unordered_map>
#include <memory>
#include <vector>
#include <variant>

enum class Type {
    keyword,
    identifier,
    literal,
    operator_type,
    separator
};

struct Operator {
public:
    enum class Type {
        unary,
        binary,
    };

    Type type = Type::unary;
    int precedence = 0;
    std::string_view  associativity = "left-to-right";

public:
    Operator(Type type, int precedence, std::string_view associativity)
        : type(type), precedence(precedence), associativity(associativity)
    {
        if (precedence < 0)
            throw std::invalid_argument("Precedence must be non-negative");

        if (associativity != "left-to-right" && associativity != "right-to-left")
            throw std::invalid_argument("Invalid associativity");
    }
};

struct UnaryOperator : public Operator {
    std::string_view operand;

    UnaryOperator(Type type, int precedence, std::string_view associativity,
                  std::string_view operand)
        : Operator(type, precedence, associativity), operand(operand) {}
};

struct BinaryOperator : public Operator {
    std::string_view left_operand, right_operand;

    BinaryOperator(Type type, int precedence, std::string_view associativity,
                  std::string_view operand)
    : Operator(type, precedence, associativity), left_operand(left_operand), right_operand(right_operand) {}
};

struct Keyword {
    std::string_view name;
    Type type;
};

class KeywordSystem {
private:
    std::vector<Keyword> keywords;

public:
    KeywordSystem() {
        keywords = {
                {"int", Type::keyword},
                {"float", Type::keyword},
                {"char", Type::keyword},
                {"return", Type::keyword},
        };
    }

    Keyword getKeyword(const std::string_view& name) const {
        for (const auto& keyword: keywords)
            if (keyword.name == name)
                return keyword;
        throw std::logic_error("Not a valid keyword");
    }
};

enum class SeparatorType {
    paranthesis,
    brace,
    comma,
    semicolon,
    unknown,
};

struct Separator {
    SeparatorType type;
    bool isPaired;
};

class SeparatorSystem{
private:
    std::unordered_map<std::string_view, Separator> separator_map;

public:
    SeparatorSystem() {
        separator_map["("] = Separator{SeparatorType::paranthesis, true};
        separator_map[")"] = Separator{SeparatorType::paranthesis, false};
        separator_map["{"] = Separator{SeparatorType::brace, true};
        separator_map["}"] = Separator{SeparatorType::brace, false};
        separator_map[","] = Separator{SeparatorType::comma, false};
        separator_map[";"] = Separator{SeparatorType::semicolon, false};
    }

    Separator getSeparator(const std::string_view& separator) {
        auto it = separator_map.find(separator);
        if (it == separator_map.end())
            return Separator{SeparatorType::unknown, false};
        return it->second;
    }
};

// keyword, identifier, literal, operator, separator
using Token = std::variant<Keyword, std::string, std::variant<int, float, char>, Operator, Separator>;
