#include "cpm/material.h"

namespace cpm {
    Material::Material(double density, double yieldStrength) :
        density(density),
        yieldStrength(yieldStrength) {}
}