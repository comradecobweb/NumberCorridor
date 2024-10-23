cmake_minimum_required(VERSION 3.22)
project(NumberCorridor)

set(CMAKE_CXX_STANDARD 17)


set(CMAKE_CXX_FLAGS "-static")


add_executable(NumberCorridor
        ${CMAKE_SOURCE_DIR}/src/main.cpp
        ${CMAKE_SOURCE_DIR}/src/numbers.cpp
        ${CMAKE_SOURCE_DIR}/src/terminal.cpp
        ${CMAKE_SOURCE_DIR}/src/game.cpp
        ${CMAKE_SOURCE_DIR}/src/game_builder.cpp
        ${CMAKE_SOURCE_DIR}/src/array.cpp
        ${CMAKE_SOURCE_DIR}/src/screens.cpp
)


include_directories(${CMAKE_SOURCE_DIR}/inc/)


set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})