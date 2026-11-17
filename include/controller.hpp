#pragma once

#include <vector>
#include <string>
#include <sys/types.h>

//template
#include "testchannel.hpp"

class controller {
    
    public:
        controller();
        int startup();

    private:
        int containerloop();
        int startProcesses();
        std::vector<pid_t> processes;
        bool startProcess(const std::string& executable);

        //testHandlerClass
        testchannel_ipcg_ctrl stubHandlerInstance;
};