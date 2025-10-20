#include <iostream>
#include <ngph/canvas.h>
#include "cpm/iokey.h"

bool appUp = true;

bool checkAppStatus() {
    if (cpm::IoKey::getInstance().getChar() == 'q') {
        appUp = false;
    }
}

int main() {
    while (appUp) {
        checkAppStatus();

        

        cpm::IoKey::getInstance().resetCapture();
    }

    return 0;
}