cmake_minimum_required(VERSION 3.14)
project(FiguresManagement VERSION 1.0.0 LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

 # основная прога
add_executable(${PROJECT_NAME}
        main.cpp
        Figure.h
        Pentagon.cpp
        Pentagon.h
        Hexagon.cpp
        Hexagon.h
        Octagon.cpp
        Octagon.h
        Array.cpp
        Array.h
)

 # тесты
add_executable(tests
        tests.cpp
        Figure.h
        Pentagon.cpp
        Pentagon.h
        Hexagon.cpp
        Hexagon.h
        Octagon.cpp
        Octagon.h
        Array.cpp
        Array.h
)

target_link_libraries(tests gtest_main)
 # винда 32
if(WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE _USE_MATH_DEFINES)
    target_compile_definitions(tests PRIVATE _USE_MATH_DEFINES)
endif()
