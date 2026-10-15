cmake_minimum_required( VERSION 3.22)
project(

  consumer
  VERSION 0.1.0
  LANGUAGES C
  
)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(raylib REQUIRED)
find_package(Rayliberplate CONFIG REQUIRED)

add_executable(consumer test.c)
target_link_libraries(consumer
  PUBLIC raylib
  PUBLIC Rayliberplate::rayliberplate
)

install(
  TARGETS consumer 
  RUNTIME DESTINATION bin
)

