#include <memory>
#include <vector>
#include "cpm/frame.h"
#include "beam.h"
#include "joint.h"

namespace cpm {
    class Frame::Impl {
    public:
        Impl() {};

        // owns all joints and beams
        std::vector<Joint> joints;
        std::vector<Beam> beams;
    };

    Frame::Frame() : pImpl(std::make_unique<Impl>()) {};
    
    void Frame::addJoint(double xPos, double yPos) {
        pImpl->joints.push_back(Joint(xPos, yPos));
    }

    void Frame::addBeam(
        int originIndex = 0,
        double length = 1,
        double width = 1,
        double height = 1,
        double viscosity = 1
    ) {
        Joint* originPtr = &pImpl->joints[originIndex];
        
        pImpl->beams.push_back(Beam(originPtr, length, width, height, viscosity));
    }

    FrameMap Frame::getShearMap() {

    };

    FrameMap Frame::getBendingMomentMap() {

    }

    FrameMap Frame::getLoadMap() {
        
    }
}