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
    
    void Frame::addJoint() {

    }

    void Frame::addBeam() {
        
    }
}