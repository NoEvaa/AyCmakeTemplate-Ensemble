cmake_minimum_required(VERSION 3.15)

# ==================================================
# Project

project(
    AyEnse
    VERSION 0.1.0
    LANGUAGES CXX
)

# ==================================================

include(GenerateExportHeader)

# Project options
include(cmake/Options.cmake)
# Utils 
include(cmake/Utils.cmake)
# Init cmake environment
include(cmake/Init.cmake)

# ==================================================
# Module libraries
add_subdirectory(src)

# ==================================================
# Project development environment 

if(${PROJECT_NAME}_IS_MAIN)
    # Main
    add_subdirectory(main)
endif()

