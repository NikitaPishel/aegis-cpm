#ifndef MODEL_BEAM_H
#define MODEL_BEAM_H

#include <cstdint>
#include <vector>
#include "cpm/materialStore.h"

namespace cpm {
    // Forward declaration
    class Joint;
    
    class Beam {
    private:
        double getDistributedLoads();

        double getShearForce(double xPos, double force);
        double getBendingMoment(double xPos, double force);

        double getShearStress(double yPos, double shearForce);
        double getBendingStress(double yPos, double bendingMoment);

        double getEqStress(double yPos, double shearForce, double bendingMoment);

        double getFirstMomentArea(double yPos);

    public:
        // length of the beam
        double length;

        // beam cross-section size
        double width;
        double height;

        // areas
        double cSectnArea;
        double sMomntArea;

        // Vertical forces
        double weight;

        Material material;
        double stressAllowed;

        std::vector<double> distributed;

        // Origin joint of a structure
        Joint* originPtr;

        // joints that are connected to a beam
        std::vector<Joint*> joints;

        Beam(
            Joint* originPtr = nullptr,
            double length = 1,
            double width = 1,
            double height = 1,
            Material material = MaterialStore::getInstance().getMaterial("base.iron"),
            double safetyFactor = 1
        );

        double getTotalShearForce(double xPos);
        double getTotalBendingMoment(double xPos);

        // find a point where equivalent stress is maximum
        double getTotalStress(double xPos);
        double getTotalStressPercentage(double xPos);
    };
}

#endif