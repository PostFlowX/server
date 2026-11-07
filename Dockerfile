FROM debian:trixie-slim AS builder

RUN apt-get update && apt-get install -y \
    cmake ninja-build g++ \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . /app/

RUN cmake -S . -B build -G Ninja \
    -DCMAKE_BUILD_TYPE=Release

RUN cmake --build build --parallel


FROM debian:trixie-slim AS runtime

WORKDIR /app

COPY --from=builder /app/build/ /app/

ENTRYPOINT ["/app/controller"]

