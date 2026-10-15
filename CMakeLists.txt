# Build the stuff
cmake_minimum_required(VERSION 3.22)
project(
    Rayliberplate
    VERSION 0.1.0
    DESCRIPTION "a minuscule, QoL-first wrapper for raylib"
    LANGUAGES C
)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(raylib CONFIG REQUIRED)

add_library(
    rayliberplate  
    src/rayliberplate.c
)

add_library(
    Rayliberplate::rayliberplate ALIAS rayliberplate
)

target_include_directories(
    rayliberplate 
    PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_link_libraries(rayliberplate PRIVATE raylib)

install(
    TARGETS rayliberplate
    EXPORT RayliberplateTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
    FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/rayliberplate.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
    EXPORT RayliberplateTargets
    FILE RayliberplateTargets.cmake
    NAMESPACE Rayliberplate::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Rayliberplate
)

configure_package_config_file(
    cmake/RayliberplateConfig.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/RayliberplateConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Rayliberplate
)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/RayliberplateConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(
    FILES
    "${CMAKE_CURRENT_BINARY_DIR}/RayliberplateConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/RayliberplateConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Rayliberplate
)
