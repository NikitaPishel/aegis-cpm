#ifndef MODEL_JOINT_H
#define MODEL_JOINT_H

#include <cstdint>
#include <vector>

namespace cpm {
    class Beam;
    
    class Joint {
    private:
        // position of a 
        const double xPos;
        const double yPos;

    public:
        Joint(double xPos = 0, double yPos = 0);

        // Beams that cross that joint
        std::vector<Beam*> beams;
    };
}

#endif