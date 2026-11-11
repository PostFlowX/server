#pragma once

//Plugin management process
class pmp {
    public:
        int start();
        bool alive;

    private:
        void aliveMessage();
        int containerloop(); //int bc ec
};