# Build the stuff
cmake_minimum_required(VERSION 3.22)
project(

    Rayliberplate
    VERSION 0.1.0
    DESCRIPTION "a minuscule, QoL-first wrapper for raylib"
    LANGUAGES C
    
)

include(GNUInstallDirs)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(raylib CONFIG REQUIRED)

add_library(

    rayliberplate 
    SHARED 
    src/rayliberplate.c
       
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
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}

)

install(

    FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/rayliberplate.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    
)
