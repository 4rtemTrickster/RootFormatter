add_executable(RootFormatter
    src/main.cpp

    src/Logger/Logger.h
    src/Logger/Logger.cpp

    src/FileReader/FileReader.cpp
    src/FileReader/FileReader.h

    src/TS/Parser/Parser.cpp
    src/TS/Parser/Parser.h
    src/TS/tsexp.h
    src/TS/tsexp.cpp
)

target_include_directories(RootFormatter PRIVATE
    src
    ../dep/tree-sitter-cpp/bindings/c/
)

target_link_libraries(RootFormatter
    spdlog::spdlog
    unofficial::tree-sitter::tree-sitter
    tree-sitter-cpp
)

add_dependencies(RootFormatter tree-sitter-cpp)

include(../cmake/tools.cmake)

copy_dlls(RootFormatter)
