#ifndef MODEL_JOINT_H
#define MODEL_JOINT_H

#include <cstdint>
#include <vector>

namespace cpm {
    class Beam;
    
    class Joint {
    public:
        // position of an origin
        const double xPos;
        const double yPos;

        Joint(double xPos = 0, double yPos = 0);

        // Beams that cross that joint
        std::vector<Beam*> beams;
    };
}

#endif