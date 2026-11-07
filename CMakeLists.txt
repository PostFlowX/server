cmake_minimum_required(VERSION 3.25)

project(postflowx-server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#Controller (Controller with main since he needs to be PID 1)
add_executable(controller
    src/main.cpp 
    src/controller.cpp 
)

add_executable(executioner
    src/executioner.cpp
)