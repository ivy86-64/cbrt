# 0 "/home/madeline/C_Projects/MinecraftTranslated/Renderer/ScaledResolution.cpp"
# 1 "/home/madeline/C_Projects/MinecraftTranslated/cmake-build-debug//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "/home/madeline/C_Projects/MinecraftTranslated/Renderer/ScaledResolution.cpp"




# 1 "/home/madeline/C_Projects/MinecraftTranslated/Renderer/ScaledResolution.h" 1
# 10 "/home/madeline/C_Projects/MinecraftTranslated/Renderer/ScaledResolution.h"
class ScaledResolution {
public:
    int scaledWidth;
    int scaledHeight;
    int scaleFactor;

    ScaledResolution(int width, int height) {
        this->scaledWidth = width;
        this->scaledHeight = height;

        for(scaleFactor = 1;
            scaledWidth / (scaleFactor + 1)
            >= 320 && scaledHeight / (scaleFactor + 1)
            >= 240; ++scaleFactor) {};

        scaledWidth /= scaleFactor;
        scaledHeight /= scaleFactor;
    }

};
# 6 "/home/madeline/C_Projects/MinecraftTranslated/Renderer/ScaledResolution.cpp" 2
