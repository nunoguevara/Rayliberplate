cmake_minimum_required(3.22)
project(

  consumer
  VERSION 0.1.0
  LANGUAGES C
  
)

find_package(raylib REQUIRED)
find_package(Rayliberplate REQUIRED)

add_executable(consumer test.c)
target_link_libraries(consumer
  PUBLIC raylib
  PUBLIC Rayliberplate
)
