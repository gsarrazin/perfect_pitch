cmake_minimum_required (VERSION 2.8.11)
project(Perfect_Hear)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Multimedia REQUIRED)
MESSAGE(STATUS "Qt5Multimedia_INCLUDE_DIRS: ${Qt5Multimedia_INCLUDE_DIRS}")
MESSAGE(STATUS "Qt5Multimedia_LIBRARIES: ${Qt5Multimedia_LIBRARIES}")

#include_directories( /usr/include/ )
include_directories(${Qt5Multimedia_INCLUDE_DIRS})

#set(GENERAL_FLAGS "-lSDL2 -lGL")

SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GENERAL_FLAGS}" )
SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GENERAL_FLAGS}" )

set(SOURCES
sources/main.cpp
)

add_executable(perfect_pitch ${SOURCES})
#target_link_libraries( perfect_pitch SDL2)
target_link_libraries(perfect_pitch ${Qt5Multimedia_LIBRARIES})
target_link_libraries(perfect_pitch Qt5::Widgets)


