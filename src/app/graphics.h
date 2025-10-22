#ifndef APP_GRAPHICS_H
#define APP_GRAPHICS_H

#include <ngph/canvas.h>
#include <ngph/texture.h>
#include "cpm/frame.h"
#include "cpm/frameMap.h"
#include "texpack.h"

namespace cpm {
    class App;
    
    class Graphics {
    private:
        struct GradColor {
            std::string color;
            double top;
            double bottom;
            
            GradColor(std::string color = "", double bottom = 0, double top = 1);
        };

        // frame pointer, used for rendering frame
        Frame* fPtr;
    
        TexPack texpack;
        gph::Canvas canvas;

        GradColor colorTable[9];

        std::string getColorByGradient(double gradient);

        gph::Texture texturizeNormalMap(const FrameMap& map);
        gph::Texture texturizeGradientMap(const FrameMap& map);

        void updateCanvas();

    public:
        Graphics();

        void linkFrame(Frame* fPtr);
        void handleImage();
    };
}

#endif