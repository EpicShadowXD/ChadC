#include <iostream>

#include "tokenizer.hpp"

int main() {
//    std::string input(scanner("input.txt"));
    std::string input =  "int main() {\n"
                         "    int a = 2 + 3;\n"
                         "    a += 3 * 4 + 5;\n"
                         "    return a;\n"
                         "}";

    auto tokens = tokenizer(input);
}
