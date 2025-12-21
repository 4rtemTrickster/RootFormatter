
add_library(RootFormatterLib STATIC

    src/Logger/Logger.h
    src/Logger/Logger.cpp

    src/FileReader/FileReader.cpp
    src/FileReader/FileReader.h

    src/Text/Text.cpp
    src/Text/Text.h

    src/TS/Types.h
    src/TS/Types.cpp

    src/Tools/Tools.h
    src/Tools/Tools.cpp

    src/Formatter/Formatter.h
    src/Formatter/Formatter.cpp
)

target_include_directories(RootFormatterLib PUBLIC
    src
)

target_link_libraries(RootFormatterLib PUBLIC
    spdlog::spdlog
    Boost::boost
    tree_sitter_cpp
    unofficial::tree-sitter::tree-sitter
)
