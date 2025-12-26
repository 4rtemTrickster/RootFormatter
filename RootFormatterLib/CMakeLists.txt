
add_library(RootFormatterLib SHARED

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

set_target_properties(RootFormatterLib PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
                      LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
                      )

target_include_directories(RootFormatterLib PUBLIC
    src
    ../dep/tree-sitter-cpp/bindings/c/
)

target_link_libraries(RootFormatterLib PUBLIC
    spdlog::spdlog
    Boost::boost
    tree-sitter-cpp
    unofficial::tree-sitter::tree-sitter
)

#add_dependencies(RootFormatterLib tree-sitter-cpp)
#
#include(../cmake/tools.cmake)
#
#copy_dlls(RootFormatterLib)
