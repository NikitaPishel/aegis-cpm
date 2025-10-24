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
            // find cross sectional area and second moment area
            cSectnArea = width * height;
            sMomntArea = (width * pow(height, 3)) / 12;

            // find weight of a beam
            weight = material.density * cSectnArea * length * 9.80665;

            stressAllowed = material.yieldStrength / safetyFactor;
        }

        double Beam::getShearForce(double xPos, double force) {
            return (force/2) - ((force * xPos) / length);
        }

        double Beam::getBendingMoment(double xPos, double force) {
            return (force * xPos) / 2 - (force * pow(xPos, 2)) / (2 * length) - (force * length) / 12;
        }

        double Beam::getFirstMomentArea(double yPos) {
            return (width / 2) * (pow(height / 2, 2) - pow(yPos, 2));
        }

        double Beam::getShearStress(double yPos, double shearForce) {
            return (shearForce * getFirstMomentArea(yPos)) / (sMomntArea * width);
        }

        double Beam::getBendingStress(double yPos, double bendingMoment) {
            return bendingMoment * yPos / sMomntArea;
        }

        double Beam::getEqStress(double yPos, double shearForce, double bendingMoment) {
            return sqrt(pow(getBendingStress(yPos, bendingMoment), 2) + (3 * pow(getShearStress(yPos, shearForce), 2)));
        }

        double Beam::getTotalShearForce(double xPos) {
            
            double totalForce = this->getShearForce(xPos, this->weight);
            
            for (int i = 0; i < this->distributed.size(); i++) {
                totalForce += this->getShearForce(xPos, this->distributed[i]);
            }

            return totalForce;
        }

        double Beam::getTotalBendingMoment(double xPos) {
            
            double totalMoment = this->getBendingMoment(xPos, this->weight);

            for (int i = 0; i < this->distributed.size(); i++) {
                totalMoment += this->getBendingMoment(xPos, this->distributed[i]);
            }

            return totalMoment;
        }

        double Beam::getTotalStress(double xPos) {
            // find a forces shear at a poistion
            double totalShear = this->getTotalShearForce(xPos);
            double totalMoment = this->getTotalBendingMoment(xPos);

            // end point is the furthest point from central axis, while yPos = 0 is at neutral axis directly
            double endPoint = height / 2;

            // find a size of 1 step if we do (100 / safety factor) steps
            double step = endPoint / 50;

            // find maximum stress in a beam
            // iterate through neutral axis distances and find max equivalent stress among those 100 steps
            double maxEqStress = 0.0;
            for (double yPos = 0; yPos <= endPoint; yPos += step) {
                double eqStress = getEqStress(yPos, totalShear, totalMoment);

                if (eqStress > maxEqStress) {
                    maxEqStress = eqStress;
                }
            }

            return maxEqStress;
        }

        double Beam::getTotalStressPercentage(double xPos) {
            return getTotalStress(xPos) / stressAllowed;
        }
}