#include <cmath>
#include "beam.h"
#include "joint.h"

namespace cpm {
    Beam::Beam(
        Joint* originPtr,
        double length,
        double width,
        double height,
        Material material,
        double safetyFactor
        ) :
        originPtr(originPtr),
        length(length),
        width(width),
        height(height),
        material(material)
        {
            // find cross sectional area
            cSectnArea = width * height;

            // find weight of a beam
            weight = material.density * cSectnArea * length;

            stressAllowed = material.yieldStrength * safetyFactor;
        }

        double Beam::getShearForce(double pos, double force) {
            return (force/2) - ((force * pos) / 2);
        }

        double Beam::getBendingMoment(double pos, double force) {
            return (force * pos) / 2 - (force * pow(pos, 2)) / (2 * length) - (force * length) / 12;
        }

        double Beam::getTotalShearForce(double pos) {
            
            double totalForce = this->getShearForce(pos, this->weight);
            
            for (int i = 0; i < this->distributed.size(); i++) {
                totalForce += this->getShearForce(pos, this->distributed[i]);
            }

            return totalForce;
        }

        double Beam::getTotalBendingMoment(double pos) {
            
            double totalMoment = this->getBendingMoment(pos, this->weight);

            for (int i = 0; i < this->distributed.size(); i++) {
                totalMoment += this->getBendingMoment(pos, this->distributed[i]);
            }

            return totalMoment;
        }

        double Beam::getTotalStress(double pos) {
            double totalShear = this->getTotalShearForce(pos);
            double totalMoment = this->getTotalBendingMoment(pos);
            
            return 0.0;
        }

        double Beam::getTotalStressPercentage(double pos) {
            return getTotalStress(pos) / stressAllowed;
        }
}