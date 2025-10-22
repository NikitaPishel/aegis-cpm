#include <memory>
#include <vector>
#include <stdexcept>
#include <cmath>
#include "cpm/frame.h"
#include "cpm/frameMap.h"
#include "beam.h"
#include "joint.h"

namespace cpm {
    class BeamBuilder {
    public:
        int xStart;
        int yStart;

        int xSize;
        int ySize;

        BeamBuilder(Beam beam) {
            // flip orientation to make map horizontal
            xStart = std::floor(beam.originPtr->yPos * 2.0);
            yStart = std::floor(beam.originPtr->xPos);

            xSize = std::floor(beam.length * 2.0);
            ySize = std::floor(beam.width);

            if (ySize == 0) {
                ySize = 1;
            }
        };
    };

    class Frame::Impl {
    public:
        Impl() {};
        
        // owns all joints and beams
        std::vector<Joint> joints;
        std::vector<Beam> beams;

        double safetyFactor;

        FrameMap getEmptyMap();
    };

    FrameMap Frame::Impl::getEmptyMap() {
        int xSize = 0;
        int ySize = 0;

        for (int i = 0; i < beams.size(); i++) {
            Joint* origin = beams[i].originPtr;

            if (!origin) {
                throw std::runtime_error("Beam has no origin");
            }
            
            // flip the matrix to make it horizontal
            int currXSize = std::floor((origin->yPos + beams[i].length) * 2.0);
            int currYSize = std::floor(origin->xPos + beams[i].width);

            if (currXSize > xSize) {
                xSize = currXSize;
            }

            if (currYSize > ySize) {
                ySize = currYSize;
            }
        }

        return FrameMap(xSize, ySize);
    }

    Frame::Frame() : pImpl(std::make_unique<Impl>()) {};

    Frame::~Frame() {}
    
    void Frame::addJoint(double xPos, double yPos) {
        pImpl->joints.push_back(Joint(xPos, yPos));
    }

    void Frame::addBeam(
        int originIndex,
        double length,
        double width,
        double height,
        Material material
    ) {
        Joint* originPtr = &pImpl->joints[originIndex];
        
        pImpl->beams.push_back(Beam(originPtr, length, width, height, material));
    }

    void Frame::setSafetyFactor(double safetyFactor) {
        pImpl->safetyFactor = safetyFactor;
    }

    FrameMap Frame::getPosMap() {
        FrameMap posMap = pImpl->getEmptyMap();

        for (int i = 0; i < pImpl->beams.size(); i++) {
            BeamBuilder builder(pImpl->beams[i]);

            for (int yShift = 0; yShift < builder.xSize; yShift++) {
                for (int xShift = 0; xShift < builder.ySize; xShift++) {
                    int xPos = builder.xStart + xShift;
                    int yPos = builder.yStart + yShift;
                    
                    if (xPos >= 0 && xPos < posMap.getXSize() && yPos >= 0 && yPos < posMap.getYSize()) {
                        posMap.setValue(xPos, yPos, 1);
                    }
                }
            }
        }

        return posMap;
    }

    FrameMap Frame::getShearMap() {
        FrameMap posMap = pImpl->getEmptyMap();

        for (int i = 0; i < pImpl->beams.size(); i++) {
            BeamBuilder builder(pImpl->beams[i]);

            for (int yShift = 0; yShift < builder.xSize; yShift++) {
                for (int xShift = 0; xShift < builder.ySize; xShift++) {
                    int xPos = builder.xStart + xShift;
                    int yPos = builder.yStart + yShift;
                    
                    if (xPos >= 0 && xPos < posMap.getXSize() && yPos >= 0 && yPos < posMap.getYSize()) {
                        double physPos = yShift / 2;
                        posMap.setValue(xPos, yPos, pImpl->beams[i].getTotalShearForce(physPos));
                    }
                }
            }
        }

        return posMap;
    }

    FrameMap Frame::getBendingMomentMap() {
        FrameMap posMap = pImpl->getEmptyMap();

        for (int i = 0; i < pImpl->beams.size(); i++) {
            BeamBuilder builder(pImpl->beams[i]);

            for (int yShift = 0; yShift < builder.xSize; yShift++) {
                for (int xShift = 0; xShift < builder.ySize; xShift++) {
                    int xPos = builder.xStart + xShift;
                    int yPos = builder.yStart + yShift;
                    
                    if (xPos >= 0 && xPos < posMap.getXSize() && yPos >= 0 && yPos < posMap.getYSize()) {
                        double physPos = yShift / 2;
                        posMap.setValue(xPos, yPos, pImpl->beams[i].getTotalBendingMoment(physPos));
                    }
                }
            }
        }

        return posMap;
    }

    FrameMap Frame::getStressMap() {
        FrameMap posMap = pImpl->getEmptyMap();

        for (int i = 0; i < pImpl->beams.size(); i++) {
            BeamBuilder builder(pImpl->beams[i]);

            for (int yShift = 0; yShift < builder.xSize; yShift++) {
                for (int xShift = 0; xShift < builder.ySize; xShift++) {
                    int xPos = builder.xStart + xShift;
                    int yPos = builder.yStart + yShift;
                    
                    if (xPos >= 0 && xPos < posMap.getXSize() && yPos >= 0 && yPos < posMap.getYSize()) {
                        double physPos = yShift / 2;
                        posMap.setValue(xPos, yPos, pImpl->beams[i].getTotalStressPercentage(physPos));
                    }
                }
            }
        }

        return posMap;
    }
}