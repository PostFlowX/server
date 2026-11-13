#include "fs.hpp"

#include <iostream>
#include <sys/wait.h>

int fsHandler::start() {
    alive = true;
    aliveMessage();

    //loop in here or else i would need to make it public
    return containerloop();
}

void fsHandler::aliveMessage() {
    std::cout << "FsHa: I am Alive!! | Set alive: " << alive << std::endl;
}

int fsHandler::containerloop() {
    while(true) {
        //Placeholder

        sleep(1);
    }

    return 0;
}