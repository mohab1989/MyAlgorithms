cmake_minimum_required(VERSION 3.2)
set(SORTING_VERSION_MAJOR 1)
set(SORTING_VERSION_MINOR 0)
project(Sorting)
set(SOURCES main.cpp)
add_executable(Sorting ${SOURCES})
target_include_directories(Sorting PUBLIC ${PROJECT_SOURCE_DIR}/include)
set_target_properties(Sorting PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)