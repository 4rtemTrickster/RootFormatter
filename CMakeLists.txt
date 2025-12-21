cmake_minimum_required(VERSION 3.13)

project(RootFormatter
    VERSION 0.1
    LANGUAGES CXX
)


if(CMAKE_PROJECT_NAME STREQUAL RootFormatter)

    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
    set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    find_package(unofficial-tree-sitter CONFIG REQUIRED)
    message(STATUS "unofficial-tree-sitter found: ${unofficial-tree-sitter_VERSION}")

    find_package(Boost CONFIG REQUIRED)
    message(STATUS "Boost found: ${Boost_VERSION}")

    find_package(spdlog CONFIG REQUIRED)
    message(STATUS "spdlog found: ${spdlog_VERSION}")

    find_package(GTest CONFIG REQUIRED)
    message(STATUS "GTest found: ${GTest_VERSION}")
endif()


add_subdirectory(RootFormatterLib)
add_subdirectory(RootFormatter)
add_subdirectory(RootFormatterTests)
