include(FetchContent)

FetchContent_Declare(
    tree_sitter
    GIT_REPOSITORY https://github.com/tree-sitter/tree-sitter.git
    GIT_TAG v0.20.8
)

FetchContent_Declare(
    tree_sitter_cpp
    GIT_REPOSITORY https://github.com/tree-sitter/tree-sitter-cpp.git
    GIT_TAG v0.20.0
)

FetchContent_MakeAvailable(tree_sitter tree_sitter_cpp)

add_library(tree_sitter_cpp_lib STATIC
    ${tree_sitter_cpp_SOURCE_DIR}/src/parser.c
    ${tree_sitter_cpp_SOURCE_DIR}/src/scanner.cc
)

target_include_directories(tree_sitter_cpp_lib PUBLIC
    ${tree_sitter_SOURCE_DIR}/lib/include
    ${tree_sitter_cpp_SOURCE_DIR}/src
)

add_library(RootFormatterLib

    src/Logger/Logger.h
    src/Logger/Logger.cpp

    src/FileReader/FileReader.cpp
    src/FileReader/FileReader.h

    src/Text/Text.cpp
    src/Text/Text.h

    src/TS/tsexp.h
    src/TS/tsexp.cpp
)

target_include_directories(RootFormatterLib PUBLIC
    src
)

target_link_libraries(RootFormatterLib
    spdlog::spdlog
    Boost::boost
    tree_sitter_cpp_lib
)

add_dependencies(RootFormatterLib Boost::boost)
