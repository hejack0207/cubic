cmake_minimum_required(VERSION 3.16)

project(Cubic)


set(SOURCE_FILE  main.cpp glad.c ./imgui/imgui_demo.cpp ./imgui/imgui_draw.cpp ./imgui/imgui_impl_glfw.cpp ./imgui/imgui_impl_opengl3.cpp ./imgui/imgui_tables.cpp ./imgui/imgui_widgets.cpp ./imgui/imgui.cpp)

include_directories(include)
include_directories(include/imgui)
include_directories(./)

add_executable(cubic ${SOURCE_FILE})
target_link_libraries(cubic PRIVATE)
target_link_libraries(cubic PRIVATE m X11 pthread Xrandr Xi dl)
target_link_libraries(cubic PRIVATE GLU GL glfw)
