cmake_minimum_required(VERSION 3.25)

project(postflowx-server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#set(PROTO_DIR ${CMAKE_CURRENT_SOURCE_DIR}/proto)
#set(GENERATED_DIR ${CMAKE_CURRENT_SOURCE_DIR}/protoGen)

file(MAKE_DIRECTORY "${GENERATED_DIR}")

find_package(Protobuf REQUIRED)
find_package(gRPC CONFIG REQUIRED)

#Add a include lib (Why is #Add a fckn color, like bro why do you display colors in my CMakeLists.txt vs code?)
add_library(pfx_headers INTERFACE)
target_include_directories(pfx_headers INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(GENERATED_DIR "${CMAKE_CURRENT_SOURCE_DIR}/protoGen/v1")

add_library(pfx_proto STATIC
    "${GENERATED_DIR}/test.pb.cc"
    "${GENERATED_DIR}/test.pb.h"
    "${GENERATED_DIR}/test.grpc.pb.cc"
    "${GENERATED_DIR}/test.grpc.pb.h"
)

target_include_directories(pfx_proto PUBLIC
    "${GENERATED_DIR}"
)

target_link_libraries(pfx_proto PUBLIC
    protobuf::libprotobuf
    gRPC::grpc++
)

#Controller (Controller with main since he needs to be PID 1) //  Make a loop out of this shit later
#The Classes need to be create as separate executables since we want them to run in separate processes
add_executable(controller
    src/Ctrl/ctrl_main.cpp 
    src/Ctrl/controller.cpp 
    src/IpcG/ChannelClasses/testchannel.cpp
)
target_link_libraries(controller PRIVATE pfx_headers pfx_proto)

add_executable(executioner
    src/Exec/exec_main.cpp
    src/Exec/executioner.cpp
)
target_link_libraries(executioner PRIVATE pfx_headers pfx_proto)

add_executable(fs 
    src/FsHa/fs_main.cpp
    src/FsHa/fs.cpp
)
target_link_libraries(fs PRIVATE pfx_headers pfx_proto)

add_executable(ipc_gateway
    src/IpcG/ipc_gateway_main.cpp
    src/IpcG/ipc_gateway.cpp 
    src/IpcG/ServiceClasses/testService.cpp
)
target_link_libraries(ipc_gateway PRIVATE pfx_headers pfx_proto)

add_executable(pmp
    src/PlMP/pmp_main.cpp 
    src/PlMP/pmp.cpp
)
target_link_libraries(pmp PRIVATE pfx_headers pfx_proto)

add_executable(watchdog
    src/WaDg/watchdog_main.cpp
    src/WaDg/watchdog.cpp
)
target_link_libraries(watchdog PRIVATE pfx_headers pfx_proto)