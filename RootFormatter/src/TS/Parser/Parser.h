#pragma once

#include <tree_sitter/api.h>
struct TSParser;
struct TSLanguage;

namespace TS
{

class Parser final
{
public:

    void set_language(TSLanguage* language);

    Parser();
    explicit Parser(TSLanguage* language);
    ~Parser();

    Parser(const Parser&) = delete;
    Parser(Parser&&) = delete;
    Parser& operator = (const Parser&) = delete;
    Parser& operator = (Parser&&) = delete;


private:

    TSParser* m_parser;
};


} // namespace TS
