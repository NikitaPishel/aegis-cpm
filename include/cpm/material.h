#ifndef ACTIONS_MAIN_H
#define ACTIONS_MAIN_H

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