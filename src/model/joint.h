#ifndef MODEL_JOINT_H
#define MODEL_JOINT_H

#include <cstdint>
#include <vector>

namespace cpm {
    class Beam;
    
    class Joint {
    private:
        // position of a 
        const uint16_t xPos;
        const uint16_t yPos;

    public:
        Joint(int xPos, int yPos);

        // Beams that cross that joint
        std::vector<Beam*> beams;
    };
}

#endif