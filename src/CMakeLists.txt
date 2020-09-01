# src dir CMakeLists
cmake_minimum_required(VERSION 3.1...3.16)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# Bring in the required GTKMM headers and libs
link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})

set(
    VC_SRC
    MainViewController.cpp
)

set(
    VC_HDR
    ${PROJECT_INCLUDE_DIR}/ViewController.hpp
    ${PROJECT_INCLUDE_DIR}/MainViewController.hpp
)

add_library(viewControllers STATIC ${VC_SRC} ${VC_HDR})

target_include_directories(viewControllers PUBLIC ${PROJECT_INCLUDE_DIR})
target_link_libraries(viewControllers PUBLIC ${GTKMM_LIBRARIES})
target_compile_features(viewControllers PUBLIC cxx_std_17)