cmake_minimum_required(VERSION 3.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(RaylibProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the include directories
include_directories(${CMAKE_SOURCE_DIR}/vendor/raylib/include)
include_directories(${CMAKE_SOURCE_DIR}/vendor/imgui)
include_directories(${CMAKE_SOURCE_DIR}/vendor/rlimgui)
include_directories(${CMAKE_SOURCE_DIR}/src)

# Find all .cpp and .c files in the src directory
file(GLOB_RECURSE PROJECT_SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/src/*.c
)

# Sources
add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
    vendor/imgui/imgui.cpp
    vendor/imgui/imgui_draw.cpp
    vendor/imgui/imgui_tables.cpp
    vendor/imgui/imgui_widgets.cpp
    vendor/imgui/imgui_demo.cpp
    vendor/rlimgui/rlImGui.cpp
)

# Link Raylib
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/vendor/raylib/lib/libraylib.a)

# On Linux, link additional libraries
if (UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} GL m pthread dl rt X11)
endif()
