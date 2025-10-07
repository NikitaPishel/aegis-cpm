#include <vector>
#include "cpm/frame.h"
#include "beam.h"
#include "joint.h"

namespace cpm {
    class Frame::Impl {
    public:
        Impl() {};

        std::vector<Beam> frame;
    };

    Frame::Frame() {};
}