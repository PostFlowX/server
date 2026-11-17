FROM debian:trixie-slim AS builder

RUN apt-get update && apt-get install -y \
    build-essential cmake ninja-build g++ \
    protobuf-compiler protobuf-compiler-grpc libprotobuf-dev libgrpc++-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . /app/

#Delete protoGenDir so the files will be compiled again
RUN rm -rf /app/protoGen/v1/*

RUN protoc \                                                                                                                                                    
    --proto_path="/app/proto/" \
    --cpp_out="/app/protoGen/v1/" \
    --grpc_out="/app/protoGen/v1/" \
    --plugin=protoc-gen-grpc="$(which grpc_cpp_plugin)" \
    /app/proto/test.proto 

RUN cmake -S . -B build -G Ninja \
    -DCMAKE_BUILD_TYPE=Release

RUN cmake --build build --parallel


FROM debian:trixie-slim AS runtime

RUN apt-get update && apt-get install -y \
    libgrpc++1.51 \
    libprotobuf32 \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY --from=builder /app/build/ /app/

ENTRYPOINT ["/app/controller"]

