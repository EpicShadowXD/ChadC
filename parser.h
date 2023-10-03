#pragma once

#include "utility.h"

std::string tokenTypeToString(TokenType type) {
    switch (type) {
        case TokenType::Identifier:
            return "Identifier";
        case TokenType::Keyword:
            return "Keyword";
        case TokenType::Operator:
            return "Operator";
        case TokenType::Number:
            return "Number";
        case TokenType::Separator:
            return "Separator";
        case TokenType::Unknown:
            return "Unknown";
        default:
            return "Invalid";
    }
}

TokenType getTokenType(const std::string& word) {
    for (size_t i = 0; i < patterns.size(); ++i) {
        std::regex regexPattern(patterns[i].first);

        if (std::regex_match(word, regexPattern))
            return patterns[i].second;
    }

    return TokenType::Unknown; // If no pattern matches
}

std::vector<Token> parser(std::vector<std::string> words) {
    std::vector<Token> tokens;
    tokens.reserve(words.size());

    for (const auto& word : words)
        tokens.emplace_back(Token{getTokenType(word), word});

    return tokens;
}

