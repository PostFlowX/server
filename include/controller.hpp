#pragma once

#include <vector>
#include <string>
#include <sys/types.h>

class controller {
    
    public:
        void startup();

    private:
        void containerloop();
        int startProcesses();
        std::vector<pid_t> processes;
        bool startProcess(const std::string& executable);
        
};