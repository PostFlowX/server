#pragma once

#include <vector>
#include <string>
#include <sys/types.h>

class controller {
    
    public:
        int start();

    private:
        std::vector<pid_t> processes;

    bool startProcess(const std::string& executable);
};