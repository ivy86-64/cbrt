//
// Created by madeline on 25.10.24.
//

#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H
#include <iostream>
#include <string>
#include <fstream>

#include "Minecraft.h"

class Minecraft;

class GameSettings {
private:
    const std::string RENDER_DISTANCES[4] {"FAR", "NORMAL", "SHORT", "TINY"};
    const std::string DIFFICULTY_LEVELS[4] {"Peaceful", "Easy", "Normal", "Hard"};
    Minecraft &mc;

public:
    float musicVolume = 1.0F;
    float soundVolume = 1.0F;
    float mouseSensitivity = 0.5F;
    bool invertMouse = false;
    int renderDistance = 0;
    bool viewBobbing = true;
    bool anaglyph = false; //3D Anaglyph
    bool limitFramerate = false;
    bool fancyGraphics = true;
    std::ofstream optionsFile;

    //KEY BINDINGS



    //FUNCTIONS
    GameSettings(Minecraft& mc, std::filesystem::path minecraftDir): mc(mc) {
        minecraftDir += "/options.txt";
        optionsFile.open(minecraftDir);

        optionsFile.close();


    }

    void loadOptions();
protected:
  //  Minecraft mc;
};



#endif //GAMESETTINGS_H
