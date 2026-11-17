#include "testService.hpp"
#include <string>

grpc::Status testServiceImpl::test(
    grpc::ServerContext* context,
    const postflowx::v1::TestRequest* request,
    postflowx::v1::TestResponse* response) {

        std::string rqData = request->component();
        std::cout << "testrqData: " << rqData << std::endl;

        response->set_recved(true);
        response->set_status("Message rcved!");

        return grpc::Status::OK;
}