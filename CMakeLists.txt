cmake_minimum_required(VERSION 3.23)

set(PROJECT_NAME arcade_marioKart)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)

file( GLOB SRC src/*.cpp src/Menu/*.cpp src/SFML/*.cpp src/marioKart/*.cpp)
file (GLOB HEADERS src/*.hpp src/Menu/*.hpp src/SFML/*.hpp src/marioKart/*.hpp)

add_executable(${PROJECT_NAME}
        ${SRC}
        ${HEADERS}
)

include(build-SFML.cmake)

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_SOURCE_DIR}/assets/neon_pixel-7.ttf"
        "${CMAKE_BINARY_DIR}/assets/neon_pixel-7.ttf"
)
