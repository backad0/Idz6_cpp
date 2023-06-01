cmake_minimum_required(VERSION 3.24)
project(Idz6)

set(CMAKE_CXX_STANDARD 23)

add_executable(Idz6 main.cpp MyDictionary.cpp MyDictionary.hpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        main
        main.cpp
)
target_link_libraries(
        main
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(main)