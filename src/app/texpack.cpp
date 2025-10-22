#include "texpack.h"

namespace cpm {
    TexPack::TexPack() {
        background = gph::Texture::Builder(1, 1)
            .setPixel(0, 0, ' ', "black", "black")
            .build();

        botMenu = gph::Texture::Builder(1, 1)
        .setPixel(0, 0, ' ', "black", "yellow")
        .build();
        
        exitLabel = gph::Texture::Builder(1, 1)
            .fillTexture(' ', "black", "yellow")
            .setPixel(0, 0, 'p', "black", "yellow")
            .setPixel(1, 0, 'r', "black", "yellow")
            .setPixel(2, 0, 'e', "black", "yellow")
            .setPixel(3, 0, 's', "black", "yellow")
            .setPixel(3, 0, 's', "black", "yellow")
            .setPixel(5, 0, 'q', "black", "yellow")
            .setPixel(7, 0, 't', "black", "yellow")
            .setPixel(8, 0, 'o', "black", "yellow")
            .setPixel(9, 0, 'e', "black", "yellow")
            .setPixel(10, 0, 'x', "black", "yellow")
            .setPixel(11, 0, 'i', "black", "yellow")
            .setPixel(12, 0, 't', "black", "yellow")
            .build();
    }
}