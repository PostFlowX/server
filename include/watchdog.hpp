#pragma once

class watchdog {
    public:
        int start();
        bool alive;

    private:
        void aliveMessage();
        int containerloop(); // int bc errorcode
};