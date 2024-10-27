//
// Created by madeline on 25.10.24.
//

#ifndef FONTRENDERER_H
#define FONTRENDERER_H

#include "../Core/Minecraft.h"

class GameSettings;

class FontRenderer {
private:
    int charWidth[256];
    int fontDisplayLists;
    //IntBuffer buffer TODO
public:
    int fontTextureName = 0;

    GameSettings options();
    FontRenderer(GameSettings options);
};



#endif //FONTRENDERER_H
