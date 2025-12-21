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

add_library(tree_sitter STATIC)
message("Tree sitter source dir: ${tree_sitter_SOURCE_DIR}")
target_sources(tree_sitter
    PRIVATE
        "${tree_sitter_SOURCE_DIR}/lib/src/lib.c"
)

target_include_directories(tree_sitter
    PRIVATE
        $<BUILD_INTERFACE:${tree_sitter_SOURCE_DIR}/lib/src>
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${tree_sitter_SOURCE_DIR}/lib/include>
)

set_target_properties(tree_sitter PROPERTIES LINKER_LANGUAGE CXX)

include(../cmake/GrammarGetter.cmake)

add_grammar_from_repo(tree_sitter_cpp                 # Defines the library name for a grammar
  https://github.com/tree-sitter/tree-sitter-cpp.git  # Repository URL of a tree-sitter grammar
  0.23.4                                               # Version tag for the grammar
)

#########################################################################################

add_library(RootFormatterLib

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
    tree_sitter
)

add_dependencies(RootFormatterLib Boost::boost)
