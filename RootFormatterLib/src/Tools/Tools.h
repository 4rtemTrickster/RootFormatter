#pragma once

#include <string>

#include "tree_sitter/api.h"


namespace Tools
{

void print_exceptions(const std::exception& ex, int level = 0);

void print_tree(TSNode node, const std::string& source, int depth = 0);

}  // namespace Tools

