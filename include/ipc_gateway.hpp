#pragma once

class ipc_gateway {
    public:
        int start();
        bool alive;

    private:
        void aliveMessage();
        int containerloop(); //int cause error code
};