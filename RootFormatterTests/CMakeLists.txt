add_executable(RootFormatterTests
    src/tmp_tests.cpp
)

target_link_libraries(RootFormatterTests RootFormatterLib GTest::gtest GTest::gtest_main)
