#ifndef MATERIAL_HOLDER_H
#define MATERIAL_HOLDER_H

#include <memory>

namespace cpm {
    class Material {
    public:
        Material(double density = 1, double yieldStrength = 1);

        double density;
        double yieldStrength;
    };
}

#endif