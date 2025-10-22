#include <ngph/texture.h>
#include "graphics.h"
#include "cpm/app.h"
#include "cpm/frame.h"

using namespace gph;

namespace cpm {
    Graphics::GradColor::GradColor(std::string color, double bottom, double top) : color(color), bottom(bottom), top(top) {}
    
    Graphics::Graphics() :
    colorTable{
        GradColor("bRed", 1, 1e6),
        GradColor("red", 0.75, 1),
        GradColor("bYellow", 0.5, 0.75),
        GradColor("yellow", 0.25, 0.5),
        GradColor("white", -0.25, 0.25),
        GradColor("cyan", -0.5, -0.25),
        GradColor("bCyan", -0.75, -0.5),
        GradColor("blue", -1, -0.75),
        GradColor("bBlue", -1e6, -1)
    }
    {

    }

    std::string Graphics::getColorByGradient(double gradient) {
        for (int i = 0; i < 9; i++) {
            if (gradient >= colorTable[i].bottom && gradient < colorTable[i].top) {
                return colorTable[i].color;
            }
        }

        return "white";
    }
    
    Texture Graphics::texturizeNormalMap(const FrameMap& map) {
        Texture::Builder mapTex(map.getXSize(), map.getYSize());

        for (int yPos = 0; yPos < map.getYSize(); yPos++) {
            for (int xPos = 0; xPos < map.getXSize(); xPos++) {
                double filled = map.getValue(xPos, yPos);

                if (filled) {
                    mapTex.setPixel(xPos, yPos, ' ', "white", "white");
                }
            }
        }

        return mapTex.build();
    }

    Texture Graphics::texturizeGradientMap(const FrameMap& map) {
        Texture::Builder mapTex(map.getXSize(), map.getYSize());

        for (int yPos = 0; yPos < map.getYSize(); yPos++) {
            for (int xPos = 0; xPos < map.getXSize(); xPos++) {
                double value = map.getValue(xPos, yPos);
                double gradient = value / map.getMaxMagnitude();

                mapTex.setPixel(xPos, yPos, ' ', "white", getColorByGradient(gradient));
            }
        }

        return mapTex.build();
    }
}