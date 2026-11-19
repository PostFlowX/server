#include "ipc_gateway.hpp"

#include <iostream>
//#include <sys/wait.h>
#include <thread>
#include <filesystem>

ipc_gateway::ipc_gateway() {
    //testchannel_ctrl = std::make_unique<testchannel_ipcg_ctrl>();
    tSimp = std::make_unique<testServiceImpl>();
}

int ipc_gateway::start() {
    alive = true;
    aliveMessage();

    //Prepare file structure
    prepareFs();

    //TODO: Make this if statement with ! and error message 
    if (startIPCserver()) {
        std::cout << "IpcG: Started gRPC IPC-Server!" << std::endl;
    }
    //ipcServer->Wait(); //Not needed since containerloop keeps process alive

    return containerloop();
}

void ipc_gateway::aliveMessage() {
    std::cout << "IpcG: I am Alive!! | Set alive: " << alive << std::endl;
}

//this loop also hold the server thread alive i suppose
int ipc_gateway::containerloop() {
    while (true) {
        //Placeholder

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 0;
}

//This initialises and starts the ipc server inside the ipc gateway
bool ipc_gateway::startIPCserver() {
    //init the builder
    grpc::ServerBuilder builder;

    builder.AddListeningPort( 
        "0.0.0.0:50051",
        grpc::InsecureServerCredentials()
    );
    //Testpurpose
    builder.AddListeningPort(
        "unix:/run/postflowx/ctrl/ctrl.sock",
        grpc::InsecureServerCredentials()
    );

    //now the grpc services
    builder.RegisterService(tSimp.get());

    // build n ship it
    ipcServer = builder.BuildAndStart();

    return ipcServer != nullptr; //server started properly
}

//This stops it as you can see
bool ipc_gateway::stopIPCserver() {
    if (ipcServer) {
        ipcServer->Shutdown();
    }

    return true; //server stopped properly
};

//inits the folders for sockets which will be used for internal gRPC communication
void ipc_gateway::prepareFs() {
    std::filesystem::create_directories("/run/postflowx/Exec"); //executioner
    std::filesystem::create_directories("/run/postflowx/IpcG"); //*Prolly wont be used i guess
    std::filesystem::create_directories("/run/postflowx/WaDg"); //Watchdog
    std::filesystem::create_directories("/run/postflowx/FsHa"); //Filesystemhandler
    std::filesystem::create_directories("/run/postflowx/Ctrl"); //Controller
    std::filesystem::create_directories("/run/postflowx/PlMP"); //Plugin Management Process
}