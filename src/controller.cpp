#include "./include/controller.hpp"

#include <spawn.h>
#include <sys/wait.h>
#include <iostream>

//Starts the controller class
int controller::start() {
    std::cout << "Ctr: [Controller] starting... \n";
    //Working Dir in CMakeList will be app/
    startProcess("app/executioner");

    return 0;
}

//Starts one process with given exec
bool controller::startProcess(const std::string& executable) {
    pid_t pid;

    //Sets arguments for posix spawn
    char* args[]= {
        const_cast<char*>(executable.c_str()),
        nullptr
    };

    //Spawns in the new process
    int result = posix_spawn(
        &pid,
        executable.c_str(),
        nullptr,
        nullptr,
        args,
        environ
    );

    //If Result is any other error code then 0 (Which means all good)
    if (result != 0)
    {
        std::cerr << "Failed to start: " << executable << '\n';
        return false;
    }

    //Insert pid into processes vector
    processes.push_back(pid);

    std::cout << "Started " << executable << " with PID " << pid << '\n';

    return true;
}
