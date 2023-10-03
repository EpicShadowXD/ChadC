#include <iostream>

#include "tokenizer.h"
#include "parser.h"

void printTokens(const std::vector<Token>& tokens) {
    for (const Token& token : tokens) {
        std::string typeStr = tokenTypeToString(token.type);
        std::cout << "Token Type: " << typeStr << ", Value: " << token.value << std::endl;
    }
}

int main() {
//    std::string input(scanner("input.txt"));
    std::string input =  "int main() {\n"
                         "    int i = 5;\n"
                         "    int a = 0;\n"
                         "    while (i != 0) {\n"
                         "        a = a + i;\n"
                         "        --i;\n"
                         "    }\n"
                         "    return a;\n"
                         "}\n";

    auto words = tokenizer(input);
    auto tokens = parser(words);

    printTokens(tokens);
}
