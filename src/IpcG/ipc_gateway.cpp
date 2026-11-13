#include "ipc_gateway.hpp"

#include <iostream>
#include <sys/wait.h>

ipc_gateway::ipc_gateway() {
    testchannel_ctrl = std::make_unique<testchannel_ipcg_ctrl>();
}

int ipc_gateway::start() {
    alive = true;
    aliveMessage();

    return containerloop();
}

void ipc_gateway::aliveMessage() {
    std::cout << "IpcG: I am Alive!! | Set alive: " << alive << std::endl;
}

int ipc_gateway::containerloop() {
    while (true) {
        //Placeholder

        sleep(1);
    }
    return 0;
}