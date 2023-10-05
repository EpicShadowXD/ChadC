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

#include "TokenTypeHierarchy.h"
#include "TokenPatterns.hpp"

namespace TTH = TokenTypeHierarchy;
using TokenType = std::variant <TTH::Keywords,
        TTH::ArithmeticOperators,
        TTH::AssignmentOperators,
        TTH::Separators,
        TTH::Identifier,
        TTH::Number
>;

struct Token {
    TokenType type;
};