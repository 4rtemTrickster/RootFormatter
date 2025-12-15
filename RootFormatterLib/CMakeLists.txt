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

target_include_directories(RootFormatterLib PRIVATE
    src
    ../dep/tree-sitter-cpp/bindings/c/
    #${Boost_INCLUDE_DIRS}
)

target_link_libraries(RootFormatterLib
    spdlog::spdlog
    unofficial::tree-sitter::tree-sitter
    tree-sitter-cpp
    Boost::boost
)

add_dependencies(RootFormatterLib tree-sitter-cpp Boost::boost)

include(../cmake/tools.cmake)

#copy_dlls(RootFormatter)
