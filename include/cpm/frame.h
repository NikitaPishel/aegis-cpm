#ifndef MODEL_FRAME_H
#define MODEL_FRAME_H

#include <memory>
#include "cpm/frameMap.h"
#include "cpm/materialStore.h"

namespace cpm {
    class Frame {
    private:
        // Internal implementation of the Frame class
        class Impl;
        std::unique_ptr<Impl> pImpl;

    public:
        Frame();
        ~Frame();

        void addJoint(double xPos = 0, double yPos = 0);
        void addBeam(
            int originIndex = 0,
            double length = 1,
            double width = 1,
            double height = 1,
            Material material = MaterialStore::getInstance().getMaterial("base.iron")
        );

        void setSafetyFactor(double safetyFactor);
        
        FrameMap getPosMap();
        FrameMap getShearMap();
        FrameMap getBendingMomentMap();
        FrameMap getStressMap();
    };
}

#endif