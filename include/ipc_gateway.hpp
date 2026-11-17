#pragma once

#include <grpcpp/grpcpp.h>

#include "test.grpc.pb.h"
#include "testService.hpp"
//#include "./src/IpcG/ChannelClasses/testchannel.hpp"
//#include <memory>

class ipc_gateway {
    public:
        ipc_gateway();
        int start(); //int cause error codes; starts the process and goes into containerloop
        bool alive;

    private:
        void aliveMessage();
        int containerloop(); //int cause error code
        bool startIPCserver(); //starts with service and 
        bool stopIPCserver(); //stops the ipc server

        //server
        std::unique_ptr<grpc::Server> ipcServer;
        //services
        //testServiceImpl tSimp;
        std::unique_ptr<testServiceImpl> tSimp;
        //Channels
        //std::unique_ptr<testchannel_ipcg_ctrl> testchannel_ctrl;

};