# src dir CMakeLists
cmake_minimum_required(VERSION 3.1...3.16)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# Bring in the required GTKMM headers and libs
link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})

# convenience vars for src and includes
set(MAIN_SRC main.cpp)

# Build and link our main driver
add_executable(main ${MAIN_SRC} ${MAIN_HDR})

target_include_directories(main PUBLIC ${PROJECT_INCLUDE_DIR})
target_link_libraries(main ${GTKMM_LIBRARIES})
target_link_libraries(main viewControllers)
target_compile_features(main PUBLIC cxx_std_17)

configure_file(main.glade ${PROJECT_BINARY_DIR}/apps/main.glade COPYONLY)
