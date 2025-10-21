#ifndef MODEL_FRAME_MAP_H
#define MODEL_FRAME_MAP_H

namespace cpm {
    class FrameMap {
    private:
        int xSize;
        int ySize;
        int matrixSize;
    
        // Pointer to data in a frame
        double* matrix;
        
    public:
        FrameMap(int xSize, int ySize);
        ~FrameMap();

        void setValue(int xPos, int yPos, double value);
        double getValue(int xPos, int yPos);

        int getXSize() const;
        int getYSize() const;
    };
}

#endif