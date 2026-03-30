#include "Tools.h"

#include <iostream>

#include <boost/range/algorithm/replace.hpp>

#include "tree_sitter/parser.h"

namespace Tools
{

void print_exceptions(const std::exception& ex, int level)
{
    std::cerr << std::string(level, ' ') << "exception: " << ex.what() << "\n";
    try
    {
        std::rethrow_if_nested(ex);
    }
    catch (const std::exception& nested_exception)
    {
        print_exceptions(nested_exception, level + 1);
    }
    catch (...) {}
}

void print_tree(TSNode node, const std::string& source, int depth)
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

}  // namespace Tools
