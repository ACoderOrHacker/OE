cmake_minimum_required(VERSION 3.28)

project(OE)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# Options

option(OE_SHARED "Build shared library" ON)
option(OE_ENABLE_EXCEPTION_SUPPORTS "Enable exception supports" OFF)

file(GLOB_RECURSE OE_LIBRARY_INCLUDES "include/**.h" "include/**.hpp")
file(GLOB_RECURSE OE_LIBRARY_SOURCES "src/**.cpp")
file(GLOB_RECURSE OE_LIBRARY_MODULES "src/**.ixx")

if (OE_SHARED)
    add_library(oe SHARED)
    target_compile_definitions(oe PUBLIC OE_SHARED)
else ()
    add_library(oe STATIC)
endif ()

target_include_directories(oe PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_sources(oe
        PUBLIC FILE_SET CXX_MODULES FILES ${OE_LIBRARY_MODULES}
        PUBLIC FILE_SET HEADERS FILES ${OE_LIBRARY_INCLUDES}
        PRIVATE ${OE_LIBRARY_SOURCES})

# Tests & Benchmarks Frameworks

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.17.0
        GIT_SHALLOW ON
)

FetchContent_Declare(
        benchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG v1.9.5
        GIT_SHALLOW ON
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest benchmark)

# Tests

enable_testing()

add_executable(test_traits
        tests/test_meta.cpp)
target_sources(test_traits PRIVATE tests/test_conv.cpp)
target_link_libraries(test_traits GTest::gtest GTest::gtest_main)
