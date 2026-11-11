#pragma once

class fsHandler {
    
    public:
        int start();
        bool alive;

    private:
        void aliveMessage(); 
        int containerloop(); //int bc if smth fails inside it we give error code

};