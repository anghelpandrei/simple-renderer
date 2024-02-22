cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (simple-renderer)


#set_property(TARGET simple-renderer PROPERTY CXX_STANDARD 23)
#set_property(TARGET simple-renderer PROPERTY CXX_STANDARD_REQUIRED ON)

include_directories(vendor/glad/include vendor/stb vendor/glm vendor/imgui src)

set(CMAKE_BINARY_DIR bin)
if (APPLE)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR})
elseif (WIN32)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endif()


# Add source to this project's executable.
set(SOURCE_FILES "src/Main.cpp" "src/SimpleRenderer.h")

add_executable (simple-renderer "vendor/glad/src/glad.c" "vendor/stb/stb_image.h" "vendor/imgui/imgui.h"
				"vendor/imgui/backends/imgui_impl_opengl3.h" "vendor/imgui/backends/imgui_impl_glfw.h"
				${SOURCE_FILES} "src/Window.h" "src/Window.cpp" "src/Mesh.h" "src/Mesh.cpp"
				"src/Inputs.h" "src/Inputs.cpp" "src/Scene.h" "src/Scene.cpp" "src/Camera.h" "src/Camera.cpp"
				"src/Shader.h" "src/Shader.cpp" "src/VertexArray.h" "src/VertexArray.cpp" "src/Buffer.h"
				"src/Buffer.cpp" "src/Texture.h" "src/Texture.cpp" "src/Model.h" "src/Model.cpp"
				"src/Framebuffer.h" "src/Framebuffer.cpp" "src/Application.h" "src/Application.cpp")

target_compile_features(simple-renderer PUBLIC cxx_std_17)
set_target_properties(simple-renderer PROPERTIES CXX_EXTENSIONS OFF)


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
