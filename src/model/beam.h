#ifndef MODEL_JOINT_H
#define MODEL_JOINT_H

#include <cstdint>

namespace cpm {
    // Forward declaration
    class Joint;
    
    class Beam {
    public:
        // length of the beam
        uint16_t length;

        // beam thickness
        uint8_t width;
        uint8_t heigth;

        Joint* origin;

        Beam();
    };
}

#endif