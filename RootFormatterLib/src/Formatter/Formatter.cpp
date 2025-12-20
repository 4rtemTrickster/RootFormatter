#include "Formatter.h"

#include <exception>
#include <stdexcept>

#include "tree_sitter/api.h"

#include "TS/Types.h"

extern "C" TSLanguage* tree_sitter_cpp();


std::string Formatter::format(const std::string& source_code)
try
{
    TS::TreePtr tree = TS::TreePtr(ts_parser_parse_string
    (
          m_parser.get()
        , nullptr // old_tree
        , source_code.c_str()
        , source_code.length()
    ));

    if (nullptr == tree)
    {
        throw std::runtime_error("Source code parsing error");
    }

    const TSNode root = ts_tree_root_node(tree.get());

    return format_internal(root);
}
catch(...)
{
    std::throw_with_nested(std::runtime_error("Format error"));
}

std::string Formatter::format_internal(const TSNode& root_node)
{
    std::string result;

    return result;
}


Formatter::Formatter()
{
    m_parser = TS::ParserPtr(ts_parser_new());
    if (nullptr == m_parser)
    {
        throw std::runtime_error("Parser creation error");
    }

    TSLanguage* lang = tree_sitter_cpp();
    if (nullptr == lang)
    {
      throw std::runtime_error("Language loading error");
    }

    ts_parser_set_language(m_parser.get(), lang);
}
