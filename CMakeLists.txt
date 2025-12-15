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

    find_package(Boost CONFIG REQUIRED)
    # Boost settings
    #set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
    #set(Boost_USE_DEBUG_LIBS        OFF)  # ignore debug libs and
    #set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
    #set(Boost_USE_MULTITHREADED      ON)
    #set(Boost_USE_STATIC_RUNTIME     ON)  # link Boost Static libraries

    find_package(spdlog CONFIG REQUIRED)
    find_package(unofficial-tree-sitter CONFIG REQUIRED)

endif()


add_subdirectory(RootFormatterLib)
add_subdirectory(RootFormatter)
#add_subdirectory(RootFormatterTests)
