project(imgui)

add_library(imgui STATIC)

target_sources(imgui
    PRIVATE
        "imgui.cpp" "imgui_demo.cpp" "imgui_draw.cpp"
		"imgui_internal.h" "imgui_tables.cpp"
		"imgui_widgets.cpp" "imstb_rectpack.h"
		"imstb_textedit.h"	"imstb_truetype.h"
        "backends/imgui_impl_opengl3.cpp" "backends/imgui_impl_glfw.cpp"
    PUBLIC
        "imgui.h" "backends/imgui_impl_opengl3.h" "backends/imgui_impl_glfw.h"
)
target_link_libraries(imgui "glfw")
target_include_directories(imgui PUBLIC "backends" ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(imgui PRIVATE "../glfw/include")
