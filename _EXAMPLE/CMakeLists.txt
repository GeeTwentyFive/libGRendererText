cmake_minimum_required(VERSION 3.30...4.4)
project(GRENDERERTEXT_EXAMPLE)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(
	"$<$<CONFIG:Release>:-O2;-march=x86-64-v2>"
	"$<$<CONFIG:Debug>:-O0;-ggdb>"
)

add_executable(${PROJECT_NAME}
	"EXAMPLE.cpp"
)
if (MINGW)
	target_link_options(${PROJECT_NAME} PRIVATE "-mwindows")
endif()

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/libs")  # (for header-only libs)

set(GWINDOWER_BUILD_EXAMPLE OFF CACHE BOOL "" FORCE)
add_subdirectory("libs/libGWindower")

add_library(GRENDERERTEXT_EXAMPLE_glad
        "libs/glad/glad.c"
)

target_link_libraries(${PROJECT_NAME} PRIVATE
        GRendererText
        GWindower
        GRENDERERTEXT_EXAMPLE_glad
)