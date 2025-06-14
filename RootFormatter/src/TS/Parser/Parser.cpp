#include "Parser.h"
#include <tree_sitter/api.h>

namespace TS
{

Parser::Parser()
    : m_parser(ts_parser_new())
{}

Parser::Parser(TSLanguage* language)
 : m_parser(ts_parser_new())
{
    ts_parser_set_language(m_parser, language);
}

Parser::~Parser()
{
    ts_parser_delete(m_parser);
}

} // namespace TS
