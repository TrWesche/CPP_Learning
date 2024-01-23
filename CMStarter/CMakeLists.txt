cmake_minimum_required(VERSION 3.28.0)
project(
    CMStarter VERSION 1.0.0 
    DESCRIPTION CMStarter_Descr
    HOMEPAGE_URL http://www.github.com/project_location
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CSS_STANDARD_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(lib)
add_subdirectory(include)

list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/lib/FlexContainer")

add_executable(CMStarter main.cpp)

target_link_libraries(CMStarter PUBLIC FlexContainer)
target_include_directories(
    CMStarter PUBLIC
    "${PROJECT_BINARY_DIR}" 
    ${EXTRA_INCLUDES}
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)