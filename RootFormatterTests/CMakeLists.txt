add_executable(RootFormatterTests
    src/tmp_tests.cpp
)

target_include_directories(RootFormatterTests PUBLIC
    src
)

target_link_libraries(RootFormatterTests
    GTest::gtest
    GTest::gtest_main
    RootFormatterLib
)
