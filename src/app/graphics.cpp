#include <iostream>
#include <stdexcept>
#include <ngph/canvas.h>
#include <ngph/texture.h>
#include "graphics.h"
#include "cpm/app.h"
#include "cpm/frame.h"

using namespace gph;

namespace cpm {
    Graphics::GradColor::GradColor(std::string color, double bottom, double top) : color(color), bottom(bottom), top(top) {}
    
    Graphics::Graphics() :
    fPtr(nullptr),
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
    
    void Graphics::linkFrame(Frame* fPtr) {
        this->fPtr = fPtr;
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

    Texture Graphics::texturizeGradientMapByValue(const FrameMap& map) {
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
    
    Texture Graphics::texturizeGradientMapByMagnitude(const FrameMap& map) {
        Texture::Builder mapTex(map.getXSize(), map.getYSize());

        for (int yPos = 0; yPos < map.getYSize(); yPos++) {
            for (int xPos = 0; xPos < map.getXSize(); xPos++) {
                double gradient = map.getValue(xPos, yPos);

                mapTex.setPixel(xPos, yPos, ' ', "white", getColorByGradient(gradient));
            }
        }

        return mapTex.build();
    }

    void Graphics::updateCanvas() {
        if (!fPtr) {
            throw std::runtime_error("running updateCanvas() before frame is linked to the graphics handler");
        }
        
        // render background
        canvas.fillWithTexture(texpack.background);

        // render stress map
        FrameMap stressMap = fPtr->getStressMap();
        gph::Texture stressTex = texturizeGradientMapByMagnitude(stressMap);

        // find positions for stress map texture (it will be centred, with accounting for bottom menu)
        int stressTexXPos = (canvas.getXSize() - stressTex.getXSize()) / 2;
        int stressTexYPos = (canvas.getYSize() - 1 - stressTex.getYSize()) / 2;

        canvas.addTexture(stressTexXPos, stressTexYPos, stressTex);

        // render bottom menu
        canvas.iterateTexture(0, canvas.getYSize()-1, canvas.getXSize(), 1, texpack.botMenu);

        int labelXPos = canvas.getXSize() - texpack.exitLabel.getXSize() - 3;
        canvas.addTexture(labelXPos, canvas.getYSize()-1, texpack.exitLabel);
        
        canvas.addTexture(3, canvas.getYSize()-1, texpack.stressLabel);
    }
    
    void Graphics::handleImage() {
        bool updated = canvas.updateSize();

        if (updated) {
            updateCanvas();
            canvas.render();
        }
    }
}