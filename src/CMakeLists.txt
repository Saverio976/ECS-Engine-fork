cmake_minimum_required(VERSION 3.23)

add_subdirectory(content)
add_subdirectory(core)
add_subdirectory(server)
add_subdirectory(client)

target_sources(
    ${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)
