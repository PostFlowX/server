#include "test.grpc.pb.h"

//using postflowx;
//using v1;

//template service class which will be included by ipc_gateway
class testServiceImpl final : public postflowx::v1::testService::Service {
    public:
        grpc::Status test(
            grpc::ServerContext* context,
            const postflowx::v1::TestRequest* request,
            postflowx::v1::TestResponse* response) override;


};