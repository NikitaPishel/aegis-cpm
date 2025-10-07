cmake_minimum_required(VERSION 3.14)
project(aegis)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source directory
add_subdirectory(${CMAKE_SOURCE_DIR}/src)

include(FetchContent)

# Fetch ngph library
FetchContent_Declare(
    ngph
    GIT_REPOSITORY https://github.com/NikitaPishel/nano-gph
    GIT_TAG master
)

FetchContent_MakeAvailable(ngph)

target_link_libraries(aegis_lib PUBLIC ngph)
target_link_libraries(aegis-cpm PRIVATE aegis_lib)

# Option to enable tests (ON by default)
set(AEGIS_BUILD_TESTS ON CACHE BOOL "Build unit tests" FORCE)

if(AEGIS_BUILD_TESTS)
    enable_testing()

    # Download and unpack gtest
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
    )

    set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    # Add test subdirectory (tests directory must contain its own CMakeLists.txt)
    add_subdirectory(${CMAKE_SOURCE_DIR}/tests)
endif()