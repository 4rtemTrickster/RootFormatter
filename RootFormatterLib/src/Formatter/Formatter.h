#pragma once


#include <string>

#include "TS/Types.h"
#include "tree_sitter/api.h"

class Formatter final
{
public:
    std::string format(const std::string& source_code);
    
    Formatter();

private:

    std::string format_internal(const TSNode& root_node);

    TS::ParserPtr m_parser;

};
