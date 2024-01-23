cmake_minimum_required(VERSION 3.28)

project(
    CMakeBase VERSION 1.0.0 
    DESCRIPTION CMake_Enabled_Base
    HOMEPAGE_URL http://www.github.com/project_location
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

configure_file(TutorialConfig.h.in TutorialConfig.h)

add_subdirectory(lib)
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/lib/MathFunctions")

add_executable(CMakeBase tutorial.cxx)

target_link_libraries(CMakeBase PUBLIC MathFunctions)

target_include_directories(
    CMakeBase PUBLIC 
    "${PROJECT_BINARY_DIR}" 
    ${EXTRA_INCLUDES}
)