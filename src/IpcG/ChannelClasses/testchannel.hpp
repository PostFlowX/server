#pragma once

#include <grpcpp/grpcpp.h>
#include "protoGen/v1/test.grpc.pb.h"

class testchannel_ipcg_ctrl {
    private:
        std::shared_ptr<grpc::Channel> channel;

        std::unique_ptr<postflowx::v1::testService::Stub> stub;
};