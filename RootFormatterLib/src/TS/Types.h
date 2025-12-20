#pragma once

#include <memory>

#include <tree_sitter/api.h>

namespace TS
{

struct TreeSitterDeliter
{
    void operator () (TSParser* parser) const
    {
        if (nullptr == parser) { return; }

        ts_parser_delete(parser);
    }

    void operator () (TSTree* tree) const 
    {
        if (nullptr == tree) { return; }

        ts_tree_delete(tree);
    }
};

using ParserPtr = std::unique_ptr<TSParser, TreeSitterDeliter>;
using ParserRef = std::unique_ptr<TSParser, TreeSitterDeliter>;

using TreePtr = std::unique_ptr<TSTree, TreeSitterDeliter>;
using TreeRef = std::unique_ptr<TSTree, TreeSitterDeliter>;

}  // namespace TS
