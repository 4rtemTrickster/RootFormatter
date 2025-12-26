add_executable(RootFormatterTests
    src/tmp_tests.cpp
)

target_link_libraries(RootFormatterTests
    GTest::gtest
    GTest::gtest_main
    RootFormatterLib
    tree-sitter-cpp
    )

add_dependencies(RootFormatterTests tree-sitter-cpp)

include(../cmake/tools.cmake)

copy_dlls(RootFormatterTests)


