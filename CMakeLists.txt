cmake_minimum_required (VERSION 3.10)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project (simple-renderer)

include_directories(vendor/glad/include vendor/stb vendor/glm vendor/imgui src)

set(CMAKE_BINARY_DIR bin)
if (APPLE)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR})
elseif (WIN32)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endif()

set(LIB_FILES "vendor/glad/src/glad.c" "vendor/stb/stb_image.h" "vendor/imgui/imgui.h"
				"vendor/imgui/backends/imgui_impl_opengl3.h" "vendor/imgui/backends/imgui_impl_glfw.h")
set(SOURCE_FILES "src/Main.cpp" "src/Window.h" "src/Window.cpp" "src/Mesh.h" "src/Mesh.cpp"
				"src/Inputs.h" "src/Inputs.cpp" "src/Scene.h" "src/Scene.cpp" "src/Camera.h" "src/Camera.cpp"
				"src/Shader.h" "src/Shader.cpp" "src/VertexArray.h" "src/VertexArray.cpp" "src/Buffer.h"
				"src/Buffer.cpp" "src/Texture.h" "src/Texture.cpp" "src/Model.h" "src/Model.cpp"
				"src/Framebuffer.h" "src/Framebuffer.cpp" "src/Application.h" "src/Application.cpp")

add_executable (simple-renderer ${LIB_FILES} ${SOURCE_FILES})

add_custom_target(copy_resources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/res
        ${CMAKE_BINARY_DIR}/res
        COMMENT "Copying resources into binary directory")

add_dependencies(simple-renderer copy_resources)


option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)

add_subdirectory(vendor/glfw)

option(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
option(ASSIMP_BUILD_SAMPLES OFF)
option(ASSIMP_BUILD_TESTS OFF)
add_subdirectory(vendor/assimp)

find_package(OpenGL REQUIRED)
target_link_libraries(simple-renderer PUBLIC OpenGL::GL glfw assimp)
