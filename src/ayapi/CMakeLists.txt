cmake_minimum_required(VERSION 3.15)

# ==================================================
# Project

project(
    AyApi
    VERSION 0.1.0
    LANGUAGES CXX
)

# Module: namespace::name
set(MODULE_NAME ayapi)
set(MODULE_NS ayin)

string(TOUPPER "${MODULE_NAME}" MODULE_NAME_UPPER)

# ==================================================
# Module library

set(${MODULE_NAME}_LIB_TYPE SHARED)

file(GLOB_RECURSE ${MODULE_NAME}_HEADERS
    CONFIGURE_DEPENDS
    "include/*.h" "include/*.hpp"
    "include/*.inl" "include/*.tcc"
)

file(GLOB_RECURSE ${MODULE_NAME}_SOURCES
    CONFIGURE_DEPENDS
    "src/*.cc" "src/*.cpp" "src/*.c"
    "src/*.h" "src/*.hpp"
    "src/*.inl" "src/*.tcc"
)

add_library(
    ${MODULE_NAME}
    ${${MODULE_NAME}_LIB_TYPE}
    ${${MODULE_NAME}_HEADERS}
    ${${MODULE_NAME}_SOURCES}
)

generate_export_header(
    ${MODULE_NAME}
    BASE_NAME ${MODULE_NAME}
    EXPORT_FILE_NAME "${CMAKE_BINARY_DIR}/ext_include/${MODULE_NAME}/export.h"
)

target_include_directories(
    ${MODULE_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PUBLIC ${CMAKE_BINARY_DIR}/ext_include
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${MODULE_NAME} PUBLIC ayin::aycore)

add_library(${MODULE_NS}::${MODULE_NAME} ALIAS ${MODULE_NAME})
message(STATUS "Build `${${MODULE_NAME}_LIB_TYPE}` library `${MODULE_NS}::${MODULE_NAME}`")

