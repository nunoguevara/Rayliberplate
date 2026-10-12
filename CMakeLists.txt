# Build the stuff
cmake_minimum_required(VERSION 3.22)
project(

    Rayliberplate
    VERSION 0.1.0
    DESCRIPTION "a minuscule, QoL-first wrapper for raylib"
    LANGUAGES C
    
)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(

    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 6.0
    FIND_PACKAGE_ARGS
  
)

FetchContent_MakeAvailable(raylib)

add_library(

    rayliberplate 
    SHARED 
    include/rayliberplate.h
    src/rayliberplate.c
       
)

target_include_directories(

    rayliberplate 
    PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>

)

target_link_libraries(rayliberplate PRIVATE raylib)
