#pragma once

#include "tokenizer.h"

[[nodiscard]]
std::string scanner(const std::string& fileName) {
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "Failed to open the file";
        return {};
    }

    std::string output, line;

    while (std::getline(file, line))
        output += line + '\n';

    return output;
}

[[nodiscard]]
TokenType getTokenType(const std::string& word) {
    for (const auto& [type, pattern] : patterns) {
        const std::regex regexPattern(std::get<0>(pattern));

        if (std::regex_match(word, regexPattern))
            return type;
    }

    return TokenType::Unknown; // If no pattern matches
}

[[nodiscard]]
std::vector<Token> tokenizer(const std::string& input) {
    std::string token_pattern("(");
    for (const auto& [type, pattern] : patterns)
        token_pattern += std::get<0>(pattern) + "|";
    token_pattern[token_pattern.size() - 1] = ')';

    const std::regex token_regex(token_pattern);
    std::sregex_iterator iter(input.begin(), input.end(), token_regex), end;

    std::vector<Token> tokens;

    while (iter != end) {
        // Use the appropriate capturing group to determine the token type
        for (int i = 1; i <= 4; ++i) {
            const std::string word = (*iter)[i];

            if ((*iter)[i].length() > 0) {
                const auto type = getTokenType(word);
                tokens.push_back(Token{getTokenType(word), word});

                // DEBUG
                std::cout << "Token Type: " << std::get<1>(patterns.at(type)) << ", Value: " << word << std::endl;

                break;
            }
        }
        ++iter;
    }

    return tokens;
}