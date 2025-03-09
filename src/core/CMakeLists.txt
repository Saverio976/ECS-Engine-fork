cmake_minimum_required(VERSION 3.23)

add_subdirectory(components)
add_subdirectory(systems)

target_sources(
    ${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/componentManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/coordinator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/entityManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/getCoordinator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/loadTextures.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/mouse.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/myMath.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/networkManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/systemManager.cpp
)
