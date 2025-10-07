#ifndef MODEL_JOINT_H
#define MODEL_JOINT_H

#include <cstdint>

namespace cpm {
    class Joint {
    public:
        // point relatively to the beam connection
        uint16_t pos;    

        Joint();
    };
}

#endif