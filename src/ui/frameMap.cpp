#include <stdexcept>
#include "cpm/frameMap.h"

namespace cpm {
    FrameMap::FrameMap(int xSize, int ySize) : xSize(xSize), ySize(ySize), matrixSize(xSize * ySize) {
        matrix = new double[xSize * ySize];
    }

    FrameMap::~FrameMap() {
        delete[] matrix;
        matrix = nullptr;
    }

    void FrameMap::setValue(int xPos, int yPos, double value) {
        if (xPos < 0 || xPos >= xSize || yPos < 0 || yPos >= ySize) {
            throw std::out_of_range("FrameMap coordinates out of range in setValue)");
        }
        
        int index = (yPos * xSize) + xPos;
        
        
        matrix[index] = value;
    }
    
    double FrameMap::getValue(int xPos, int yPos) {
        if (xPos < 0 || xPos >= xSize || yPos < 0 || yPos >= ySize) {
            throw std::out_of_range("FrameMap coordinates out of range in getValue");
        }

        int index = (yPos * xSize) + xPos;

        return matrix[index];
    }
}