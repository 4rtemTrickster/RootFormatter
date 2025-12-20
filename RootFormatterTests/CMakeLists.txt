add_executable(RootFormatterTests
    src/tmp_tests.cpp
)

target_link_libraries(RootFormatterTests
    GTest::gtest
    GTest::gtest_main
    tree_sitter_cpp_lib
    RootFormatterLib
    )

