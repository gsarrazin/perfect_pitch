cmake_minimum_required (VERSION 2.8.11)
project(Perfect_Hear)

include_directories( /usr/include/ )

set(GENERAL_FLAGS "-lSDL2 -lGL")

SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GENERAL_FLAGS}" )
SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GENERAL_FLAGS}" )

set(SOURCES
sources/main.cpp
)

add_executable(Perfect_Hear ${SOURCES})
target_link_libraries( Perfect_Hear SDL2)


