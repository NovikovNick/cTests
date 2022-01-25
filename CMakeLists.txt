cmake_minimum_required(VERSION 3.20)
project(test)
find_package(OpenGL REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(removeLinkedListElements src/main/cpp/RemoveLinkedListElements.cpp)
add_executable(romanToInteger src/main/cpp/RomanToInteger.cpp)
add_executable(lemonadeChange src/main/cpp/LemonadeChange.cpp)
add_executable(interchangeableRectangles src/main/cpp/InterchangeableRectangles.cpp)
add_executable(countingBits src/main/cpp/CountingBits.cpp)
add_executable(maximumValueAfterInsertion src/main/cpp/MaximumValueAfterInsertion.cpp)
add_executable(empty src/main/cpp/empty.cpp)

include_directories(
        external_dependencies/glfw/include
        external_dependencies/glew
)

add_executable(graphic src/main/cpp/graphic/graphic_lesson_1.cpp)
add_subdirectory(external_dependencies/glfw)
target_link_libraries(graphic glfw ${GLFW_LIBRARIES} ${OPENGL_LIBRARY})