#pragma once

#include <string>
#pragma warning(push, 0)
#include "cpp-tree-sitter.h"
#pragma warning(pop)


namespace Tools
{

void print_exceptions(const std::exception& ex, int level = 0);

void print_tree(ts::Node node, const std::string& source, int depth = 0);

}  // namespace Tools

