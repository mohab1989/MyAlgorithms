cmake_minimum_required(VERSION 3.2)
set(SORTING_VERSION_MAJOR 1)
set(SORTING_VERSION_MINOR 0)
project(Sorting)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake/modules)

enable_testing()
find_package(GTest)
find_package(GMock)

set(SOURCES testing.cpp)

if(GTEST_FOUND)
add_executable(Sorting ${SOURCES})
target_include_directories(Sorting PUBLIC ${PROJECT_SOURCE_DIR}/include ${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS})
target_link_libraries(Sorting GTest::GTest GTest::Main ${GMOCK_BOTH_LIBRARIES})
set_target_properties(Sorting PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)
endif()
