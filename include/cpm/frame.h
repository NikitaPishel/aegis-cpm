#ifndef MODEL_FRAME_H
#define MODEL_FRAME_H

#include <memory>
#include "cpm/frameMap.h"

namespace cpm {
    class Frame {
    private:
        // Internal implementation of the Frame class
        class Impl;
        std::unique_ptr<Impl> pImpl;

    public:
        Frame();

        void addJoint(double xPos = 0, double yPos = 0);
        void addBeam(
            int originIndex = 0,
            double length = 1,
            double width = 1,
            double height = 1,
            double viscosity = 1
        );
        
        FrameMap getPosMap();
        FrameMap getShearMap();
        FrameMap getBendingMomentMap();
        FrameMap getLoadMap();
    };
}

#endif