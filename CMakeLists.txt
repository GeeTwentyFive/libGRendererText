cmake_minimum_required(VERSION 3.30...4.4)
project(GRendererText)
set(CMAKE_CXX_EXTENSIONS OFF)

option(GRENDERERTEXT_BUILD_EXAMPLE "Build example program" ON)

add_library(${PROJECT_NAME}
	"GRendererText.cpp"
)
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/libs")

set(GRENDERER2D_BUILD_EXAMPLE OFF CACHE BOOL "" FORCE)
add_subdirectory("libs/libGRenderer2D")

target_link_libraries(${PROJECT_NAME} GRenderer2D)

if (GRENDERERTEXT_BUILD_EXAMPLE)
        add_subdirectory(_EXAMPLE)
endif()