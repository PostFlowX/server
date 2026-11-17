#include "testchannel.hpp"

//std constr
testchannel_ipcg_ctrl::testchannel_ipcg_ctrl() {
    std::string address = "127.0.0.1:50051";

    initiateStub(address);
    std::string msg = "Test";

    if (!sendTestMessage(msg))
    {
        std::cout << "Error Msg" << std::endl;
    }
}

testchannel_ipcg_ctrl::testchannel_ipcg_ctrl(std::string &address)
{
    initiateStub(address);
    std::string msg = "Test";

    if(!sendTestMessage(msg)) {
        std::cout << "" << std::endl;
    }
}

bool testchannel_ipcg_ctrl::sendTestMessage(std::string msg) {
    //init request
    grpc::ClientContext context;
    postflowx::v1::TestRequest request;
    postflowx::v1::TestResponse response;
    
    //set request up
    request.set_component(msg);

    //Send Request
    grpc::Status RequestStatus = stub->test(&context, request, &response);

    // TODO: Still smth to do with this RequestStatus

    //read data from response that was written by the server into the reference
    bool status = response.recved();
    std::string answ = response.status();

    std::cout << "Response msg: Rcvd:" << status << " Msg: " << answ << std::endl;

    return true;
}

bool testchannel_ipcg_ctrl::initiateStub(std::string &serveraddress) {
    //first initiate channel
    channel = grpc::CreateChannel(serveraddress, grpc::InsecureChannelCredentials());
    //Create the stub
    stub = postflowx::v1::testService::NewStub(channel);

    return true;
}
