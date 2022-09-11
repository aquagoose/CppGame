cmake_minimum_required(VERSION 3.23)
project(Game)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(Game src/main.cpp src/Engine/GameWindow.cpp src/Engine/GameWindow.h src/Engine/Game.cpp src/Engine/Game.h src/Engine/Graphics.cpp src/Engine/Graphics.h src/Engine/SpriteRenderer.cpp src/Engine/SpriteRenderer.h src/Engine/Shader.cpp src/Engine/Shader.h src/Engine/Texture2D.cpp src/Engine/Texture2D.h src/Engine/stb_image.h src/Engine/Time.cpp src/Engine/Time.h)

add_subdirectory(lib/glfw)
add_subdirectory(lib/glad)
add_subdirectory(lib/glm)
include_directories(lib/)

target_link_libraries(${PROJECT_NAME} glfw glad glm)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/Content/ ${CMAKE_CURRENT_BINARY_DIR}/Content/)