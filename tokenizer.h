#pragma once

#include "utility.h"

std::string scanner(const std::string& fileName) {
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "Failed to open the file";
        return {};
    }

    std::string output;
    std::string line;

    while (std::getline(file, line))
        output += line + '\n';

    return output;
}

std::vector<std::string> tokenizer(std::string input) {
    std::string token_pattern("(");
    for (const auto& pattern : patterns)
        token_pattern += pattern.first + "|";
    token_pattern[token_pattern.size() - 1] = ')';

    std::regex token_regex(token_pattern);
    std::sregex_iterator iter(input.begin(), input.end(), token_regex);
    std::sregex_iterator end;

    std::vector<std::string> tokens;

    while (iter != end) {
        // Use the appropriate capturing group to determine the token type
        for (int i = 1; i <= 4; ++i) {
            if ((*iter)[i].length() > 0) {
                tokens.push_back((*iter)[i]);
                break;
            }
        }
        ++iter;
    }
    return tokens;
}