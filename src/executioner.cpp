#include "executioner.hpp"

#include <iostream>
#include <sys/wait.h>

int executioner::start() {
    alive = true;
    aliveMessage();

    return containerloop();
}

//TestMessage
void executioner::aliveMessage() {
    std::cout << "Exec: I am Alive!! | Set alive: " << alive << std::endl;
}

int executioner::containerloop() {
    while (true) {
        //Placeholer

        sleep(1);
    }
    return 0;
}