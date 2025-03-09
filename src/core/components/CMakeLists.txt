cmake_minimum_required(VERSION 3.23)

target_sources(
    ${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/animator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/boxCollider.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/camera.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/child.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/interactionBoxCollider.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lifeTimer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/rigidBody.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/spriteRenderer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/tag.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/text.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/trail.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/transform.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ui.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/uiButton.cpp
)
