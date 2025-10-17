#include "beam.h"

namespace cpm {
    Beam::Beam(Joint& originJoint, int length, int width, int height) :
        originJoint(&originJoint),
        length(length),
        width(width),
        height(height)
        {
            cSectnArea = width * height;
        }
}