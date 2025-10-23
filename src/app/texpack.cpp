#include "texpack.h"

namespace cpm {
    TexPack::TexPack() {
        background = gph::Texture::Builder(1, 1)
            .setPixel(0, 0, ' ', "black", "black")
            .build();

        botMenu = gph::Texture::Builder(1, 1)
        .setPixel(0, 0, ' ', "black", "yellow")
        .build();
        
        exitLabel = gph::Texture::Builder(15, 1)
            .fillTexture(' ', "black", "yellow")
            .setPixel(0, 0, 'p', "black", "yellow")
            .setPixel(1, 0, 'r', "black", "yellow")
            .setPixel(2, 0, 'e', "black", "yellow")
            .setPixel(3, 0, 's', "black", "yellow")
            .setPixel(4, 0, 's', "black", "yellow")
            .setPixel(6, 0, 'q', "black", "yellow")
            .setPixel(8, 0, 't', "black", "yellow")
            .setPixel(9, 0, 'o', "black", "yellow")
            .setPixel(11, 0, 'e', "black", "yellow")
            .setPixel(12, 0, 'x', "black", "yellow")
            .setPixel(13, 0, 'i', "black", "yellow")
            .setPixel(14, 0, 't', "black", "yellow")
            .build();
        
        stressLabel = gph::Texture::Builder(18, 1)
            .fillTexture(' ', "white", "yellow")
            .setPixel(0, 0, 'C', "bWhite", "bRed")
            .setPixel(1, 0, 'P', "bWhite", "bRed")
            .setPixel(2, 0, '+', "bWhite", "red")
            .setPixel(3, 0, ' ', "bWhite", "red")
            .setPixel(4, 0, ' ', "bWhite", "bYellow")
            .setPixel(5, 0, ' ', "bWhite", "bYellow")
            .setPixel(6, 0, ' ', "bWhite", "yellow")
            .setPixel(7, 0, ' ', "bWhite", "yellow")
            .setPixel(8, 0, 'N', "black", "white")
            .setPixel(9, 0, 'E', "black", "white")
            .setPixel(10, 0, ' ', "bWhite", "cyan")
            .setPixel(11, 0, ' ', "bWhite", "cyan")
            .setPixel(12, 0, ' ', "bWhite", "bCyan")
            .setPixel(13, 0, ' ', "bWhite", "bCyan")
            .setPixel(14, 0, ' ', "bWhite", "blue")
            .setPixel(15, 0, '-', "bWhite", "blue")
            .setPixel(16, 0, 'C', "bWhite", "bBlue")
            .setPixel(17, 0, 'P', "bWhite", "bBlue")
            .build();
    }
}