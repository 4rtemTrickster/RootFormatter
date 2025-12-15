#include "tsexp.h"

#include "TS/Types.h"
#include "Text/Text.h"
#include "tree_sitter/parser.h"

#include <boost/range/algorithm/replace.hpp>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <string>
#include <tree_sitter/api.h>

extern "C" TSLanguage* tree_sitter_cpp();


void print_tree(TSNode node, const std::string& source, int depth = 0)
{
    if (ts_node_is_null(node)) { return; }

    const std::string indent(static_cast<size_t>(depth * 4), ' ');
    const char* type = ts_node_type(node);
    std::string text;

    uint32_t start = ts_node_start_byte(node);
    uint32_t end = ts_node_end_byte(node);

    if (end > start)
    {
        text = source.substr(start, end - start);
        boost::range::replace(text, '\n', '\\');
        boost::range::replace(text, '\t', '~');
    }

    std::cout << indent << type << " [" << start << "-" << end << "]";
    if (!text.empty())
    {
        std::cout << " -> '" << text << "'";
    }
    std::cout << '\n';

    uint32_t child_count = ts_node_child_count(node);
    for (uint32_t i = 0; i < child_count; ++i)
    {
        print_tree(ts_node_child(node, i), source, depth + 1);
    }

}


void tsexp()
{
    TS::ParserPtr parser(ts_parser_new());
    const TSLanguage* language = tree_sitter_cpp();
    ts_parser_set_language(parser.get(), language);

    std::string src = R"(#include <iostream>
// blabla
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
)";

    TextTools::Text text(src);

    //TS::Tree tree(parser.parse_string(src));

    // TSNode root_node = tree.get_root_node();

    // print_tree(root_node, src);

//std::string root_node_str(ts_node_string(root_node));
//
    //std::cout << root_node_str << '\n';

}
