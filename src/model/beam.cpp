#include <cmath>
#include "beam.h"
#include "joint.h"

namespace cpm {
    Beam::Beam(Joint* originPtr, double length, double width, double height, double viscosity) :
        originPtr(originPtr),
        length(length),
        width(width),
        height(height)
        {
            // find cross sectional area
            cSectnArea = width * height;

            // find weight of a beam
            weight = viscosity * cSectnArea * length;
        }

        double Beam::getShearForce(double pos, double force) {
            return (force/2) - (force * pos);
        }

        double Beam::getBendingMoment(double pos, double force) {
            return (force * pos) / 2 - (force * pow(pos, 2)) / (2 * length) - (force * length) / 12;
        }

        double Beam::getTotalShearForce(double pos) {
            
            double totalForce = this->getShearForce(pos, this->weight);
            
            for (int i; i < this->distributed.size(); i++) {
                totalForce += this->getShearForce(pos, this->distributed[i]);
            }

            return totalForce;
        }

        double Beam::getTotalBendingMoment(double pos) {
            
            double totalMoment = this->getBendingMoment(pos, this->weight);

            for (int i; i < this->distributed.size(); i++) {
                totalMoment += this->distributed[i];
            }

            return totalMoment;
        }
}