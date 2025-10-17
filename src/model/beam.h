#ifndef MODEL_JOINT_H
#define MODEL_JOINT_H

#include <cstdint>
#include <vector>

namespace cpm {
    // Forward declaration
    class Joint;
    
    class Beam {
    public:
        // length of the beam
        uint16_t length;

        // beam cross-section size
        uint8_t width;
        uint8_t height;

        uint16_t cSectnArea;
        uint16_t fMomntArea;
        uint16_t sMomntArea;

        // Origin joint of a structure
        Joint* originJoint;

        // joints that are connected to a beam
        std::vector<Joint*> joints;

        Beam(Joint& originJoint, int length, int width, int height);
    };
}

#endif