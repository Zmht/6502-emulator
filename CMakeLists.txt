cmake_minimum_required(VERSION 3.10.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(6502-emulator)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")


add_executable(${PROJECT_NAME} src/main_6502.cpp)