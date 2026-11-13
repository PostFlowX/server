#include "controller.hpp"

#include <spawn.h>
#include <sys/wait.h>
#include <iostream>
#include <cstring>

//Boots up this instance
int controller::startup() {
    std::cout << "Ctrl: I am Alive baby!\n";
    int i = startProcesses();

    if (i != 0) {
        std::cerr << "Ctrl: My startup failed :(\n";
    }

    return containerloop();
}

//Starts the processes that will be managed by controller class
int controller::startProcesses() {
    
    std::cout << "Ctrl: Starting processes... \n";
    //Working Dir in CMakeList will be app/ so everything is in the same directory at first and ./ should do the magic
    startProcess("./executioner");
    startProcess("./fs");
    startProcess("./ipc_gateway");
    startProcess("./pmp");
    startProcess("./watchdog");

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
        std::cerr   << "Failed to start: " 
                    << executable 
                    << " | Error: "
                    << strerror(result)
                    << " | Code: "
                    << result << '\n';
        
        return false;
    }

    //Insert pid into processes vector
    processes.push_back(pid);

    std::cout << "Started " << executable << " with PID " << pid << '\n';

    return true;
}

//int because error codes
int controller::containerloop() {
    while(true) {
        //Placeholder for other stuff


        sleep(1);
    }
    return 0;
}