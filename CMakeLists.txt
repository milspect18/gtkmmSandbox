# Top-level cmake build script
cmake_minimum_required(VERSION 3.1...3.16)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# use semantic versioning
project(
    GtkMmSandbox
    VERSION 0.1.0
    DESCRIPTION "Sanbox for GTK+ C++ development"
    LANGUAGES CXX
)

# Create a var for the project specific include dir
# then add the dir to the compiler includes path
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/inc/gtkMmSandbox)

# Ensure any cmake helpers / find lib x files are in the path
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

# Get the GTKMM package
find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)

# src contains lib files and apps contains main driver code
add_subdirectory(src)
add_subdirectory(apps)
