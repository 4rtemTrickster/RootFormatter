#include "tsexp.h"

#include <iostream>
#include <ostream>
#include <string>
#include <tree_sitter/api.h>
#include <tree-sitter-cpp.h>

void tsexp()
{
    TSParser* parser = ts_parser_new(); 

    ts_parser_set_language(parser, tree_sitter_cpp());

    std::string src = R"(#include <iostream>

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
})";

    TSTree* tree = ts_parser_parse_string(parser, nullptr, src.data(), strlen(src.data()));

    TSNode root_node = ts_tree_root_node(tree);

    std::string root_node_str(ts_node_string(root_node));

    std::cout << root_node_str << '\n';

}
