cmake_minimum_required (VERSION 3.23)

project (simple-renderer)
set(BUILD_SHARED_LIBS OFF)

set(CMAKE_BINARY_DIR bin)
if (APPLE)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR})
elseif (WIN32)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endif()

add_executable (simple-renderer)

set_target_properties(simple-renderer
    PROPERTIES
        CXX_STANDARD 23
        C_STANDARD 23
)

add_subdirectory(src)
add_subdirectory(vendor)

add_custom_target(copy_resources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/res
        ${CMAKE_BINARY_DIR}/res
        COMMENT "Copying resources into binary directory")

add_dependencies(simple-renderer copy_resources)

find_package(OpenGL REQUIRED)
target_link_libraries(simple-renderer 
    PRIVATE
        "OpenGL::GL" "glfw" "assimp" "glad" "glm" "imgui"
)

target_include_directories(simple-renderer PRIVATE "src" "vendor/stb")
target_sources(simple-renderer PRIVATE "vendor/stb/stb_image.h")

