cmake_minimum_required(VERSION 3.11...3.30)

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

    find_package(spdlog CONFIG REQUIRED)
    find_package(unofficial-tree-sitter CONFIG REQUIRED)

endif()

add_subdirectory(RootFormatter)
#add_subdirectory(RootFormatterTests)
add_subdirectory(dep/tree-sitter-cpp)
