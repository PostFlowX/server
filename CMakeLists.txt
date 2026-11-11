cmake_minimum_required(VERSION 3.25)

project(postflowx-server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#Add a include lib (Why is #Add a fckn color, like bro why do you display colors in my CMakeLists.txt vs code?)
add_library(pfx_headers INTERFACE)
target_include_directories(pfx_headers INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

#Controller (Controller with main since he needs to be PID 1)
#The Classes need to be create as separate executables since we want them to run in separate processes
add_executable(controller
    src/ctrl_main.cpp 
    src/controller.cpp 
)
target_link_libraries(controller PRIVATE pfx_headers)

add_executable(executioner
    src/exec_main.cpp
    src/executioner.cpp
)
target_link_libraries(executioner PRIVATE pfx_headers)

add_executable(fs 
    src/fs_main.cpp
    src/fs.cpp
)
target_link_libraries(fs PRIVATE pfx_headers)

add_executable(ipc_gateway
    src/ipc_gateway_main.cpp
    src/ipc_gateway.cpp 
)
target_link_libraries(ipc_gateway PRIVATE pfx_headers)

add_executable(pmp
    src/pmp_main.cpp 
    src/pmp.cpp
)
target_link_libraries(pmp PRIVATE pfx_headers)

add_executable(watchdog
    src/watchdog_main.cpp
    src/watchdog.cpp
)
target_link_libraries(watchdog PRIVATE pfx_headers)