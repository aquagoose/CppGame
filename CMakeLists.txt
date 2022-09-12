cmake_minimum_required(VERSION 3.23)
project(Game)

set(CMAKE_CXX_STANDARD 17)

add_executable(Game src/main.cpp src/Engine/GameWindow.cpp src/Engine/GameWindow.h src/Engine/Game.cpp src/Engine/Game.h src/Engine/Graphics.cpp src/Engine/Graphics.h src/Engine/SpriteRenderer.cpp src/Engine/SpriteRenderer.h src/Engine/Shader.cpp src/Engine/Shader.h src/Engine/Texture2D.cpp src/Engine/Texture2D.h src/Engine/stb_image.h src/Engine/Time.cpp src/Engine/Time.h src/Engine/Input.cpp src/Engine/Input.h src/Engine/Bitmap.cpp src/Engine/Bitmap.h src/Tile.cpp src/Tile.h src/Engine/Scene.cpp src/Engine/Scene.h src/Engine/SceneManager.cpp src/Engine/SceneManager.h src/MainScene.cpp src/MainScene.h src/IntroScene.cpp src/IntroScene.h)

add_subdirectory(lib/glfw)
add_subdirectory(lib/glad)
add_subdirectory(lib/glm)
include_directories(lib/)

target_link_libraries(${PROJECT_NAME} glfw glad glm)