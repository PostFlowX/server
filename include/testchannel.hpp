#pragma once

#include <grpcpp/grpcpp.h>
#include "test.grpc.pb.h"

//Template for stub class which will be included by controller for example
//This class includes the stub and will handle it
class testchannel_ipcg_ctrl {
    public:
        testchannel_ipcg_ctrl();
        testchannel_ipcg_ctrl(std::string &address);
        bool sendTestMessage(std::string msg);

    private:
        bool initiateStub(std::string &serveraddress);
        std::shared_ptr<grpc::ChannelInterface> channel;
        std::unique_ptr<postflowx::v1::testService::Stub> stub;
};