cmake_minimum_required(VERSION 3.20)
project(Test VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)

configure_file(src/main/cpp/config/TestConfig.h.in src/main/cpp/config/TestConfig.h)

add_executable(removeLinkedListElements src/main/cpp/RemoveLinkedListElements.cpp)
add_executable(romanToInteger src/main/cpp/RomanToInteger.cpp)
add_executable(lemonadeChange src/main/cpp/LemonadeChange.cpp)
add_executable(interchangeableRectangles src/main/cpp/InterchangeableRectangles.cpp)
add_executable(countingBits src/main/cpp/CountingBits.cpp)
add_executable(maximumValueAfterInsertion src/main/cpp/MaximumValueAfterInsertion.cpp)
add_executable(empty src/main/cpp/empty.cpp)

add_executable(concurrency_fst src/main/cpp/concurrency/fst.cpp)


target_include_directories(empty PUBLIC
        "${PROJECT_BINARY_DIR}"
        )

target_include_directories(concurrency_fst PUBLIC "${PROJECT_BINARY_DIR}")
target_link_libraries(concurrency_fst Threads::Threads )