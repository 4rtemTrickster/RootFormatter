add_executable(RootFormatter
    src/main.cpp
)

target_include_directories(RootFormatter PUBLIC
    src
)

target_link_libraries(RootFormatter PUBLIC
    RootFormatterLib
    )
