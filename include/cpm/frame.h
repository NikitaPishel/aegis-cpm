#ifndef MODEL_FRAME_H
#define MODEL_FRAME_H

#include <memory>

namespace cpm {
    class Frame {
    private:
        // Internal implementation of the Frame class
        class Impl;
        std::unique_ptr<Impl> pImpl;

    public:
        Frame();

        void addJoint();
        void addBeam();
    };
}

#endif