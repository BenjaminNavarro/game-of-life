cmake_minimum_required(VERSION 3.0.2)
project(MD5Encrypter)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB sources src/*.cpp)

add_executable(game-of-life ${sources})
set_property(TARGET game-of-life PROPERTY CXX_STANDARD 17)

target_link_libraries(game-of-life ${CONAN_LIBS_FMT})
target_include_directories(game-of-life PRIVATE include ${CONAN_INCLUDE_DIRS_FMT})
