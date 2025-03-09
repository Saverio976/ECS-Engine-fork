cmake_minimum_required(VERSION 3.23)

target_sources(
    ${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/animationSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cameraSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/childSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/collisionSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/drawSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/interactionCollisionSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lifeTimerSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/physicsSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/textRenderingSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/trailSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/uiButtonSystem.cpp
)
