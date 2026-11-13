#pragma once

#include "./src/IpcG/ChannelClasses/testchannel.hpp"

//#include <memory>

class ipc_gateway {
    public:
        ipc_gateway();
        int start();
        bool alive;

    private:
        void aliveMessage();
        int containerloop(); //int cause error code

        //Channels
        std::unique_ptr<testchannel_ipcg_ctrl> testchannel_ctrl;

};