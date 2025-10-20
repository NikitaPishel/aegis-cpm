#ifndef MODEL_BEAM_H
#define MODEL_BEAM_H

#include <cstdint>
#include <vector>

namespace cpm {
    // Forward declaration
    class Joint;
    
    class Beam {
    private:
        double getDistributedLoads();

        double getShearForce(double pos, double force);
        double getBendingMoment(double pos, double force);
    
        double getTotalShearForce(double pos);
        double getTotalBendingMoment(double pos);

    public:
        // length of the beam
        double length;

        // beam cross-section size
        double width;
        double height;

        double cSectnArea;
        double fMomntArea;
        double sMomntArea;

        // Vertical forces
        double weight;

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
            double viscosity = 1
        );
    };
}

#endif