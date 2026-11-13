FROM debian:trixie-slim AS builder

RUN apt-get update && apt-get install -y \
    build-essential cmake ninja-build g++ \
    protobuf-compiler protobuf-compiler-grpc libprotobuf-dev libgrpc++-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . /app/

#Delete protoGenDir so the files will be compiled again
RUN rm -rf /app/protoGen/v1/*

RUN cmake -S . -B build -G Ninja \
    -DCMAKE_BUILD_TYPE=Release

RUN cmake --build build --parallel


FROM debian:trixie-slim AS runtime

WORKDIR /app

COPY --from=builder /app/build/ /app/

ENTRYPOINT ["/app/controller"]

