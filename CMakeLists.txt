cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (simple-renderer)

include_directories(vendor/glad/include vendor/stb vendor/glm src)
# Add source to this project's executable.
add_executable (simple-renderer "vendor/glad/src/glad.c" "vendor/stb/stb_image.h" "src/Main.cpp"
				"src/SimpleRenderer.h" "src/Window.h" "src/Window.cpp" "src/Mesh.h" "src/Mesh.cpp"
				"src/Inputs.h" "src/Inputs.cpp" "src/Scene.h" "src/Scene.cpp" "src/Camera.h" "src/Camera.cpp"
				"src/Shader.h" "src/Shader.cpp" "src/VertexArray.h" "src/VertexArray.cpp" "src/Buffer.h"
				"src/Buffer.cpp" "src/Texture.h" "src/Texture.cpp" "src/Model.h" "src/Model.cpp"
				"src/Framebuffer.h" "src/Framebuffer.cpp" "src/Application.h" "src/Application.cpp")

add_custom_target(copy_resources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/res
        ${PROJECT_BINARY_DIR}/res
        COMMENT "Copying resources into binary directory")

add_dependencies(simple-renderer copy_resources)

set_property(TARGET simple-renderer PROPERTY CXX_STANDARD 23)

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
