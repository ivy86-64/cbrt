//
// Created by madeline on 26.10.24.
//

#ifndef SCALEDRESOLUTION_H
#define SCALEDRESOLUTION_H



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



#endif //SCALEDRESOLUTION_H
