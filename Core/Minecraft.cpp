//
// Created by madeline on 25.10.24.
//

#include "Minecraft.h"
#include "../Renderer/RenderEngine.h"
#include <filesystem>
#include <iostream>

#ifdef __linux__
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#endif

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../Renderer/ScaledResolution.h"
#include "../Core/GameSettings.h"

class RenderEngine;
class GameSettings;

void Minecraft::run() {
    running = true;

    try {
        startGame();
    }
    catch(int TODO) {
        std::cout <<" Fail";
    }
}

std::filesystem::path Minecraft::getAppDir() {
    std::filesystem::path minecraftDir;

    switch(getOs()) {
        case 0: {
            struct passwd *pw = getpwuid(getuid());
            minecraftDir = pw->pw_dir;
            break;
        }
        case 1: std::cout << "MacOS X is not yet supported.";
        case 2: std::cout << "Windows is not yet supported.";
    }

    minecraftDir += "/.cbrt";


    if(!exists(minecraftDir)) {
        create_directory(minecraftDir);
        std::cout << "Successfully created cbrt directory at " <<minecraftDir << '\n';

    }

    return minecraftDir;
}

int Minecraft::getOs() {
    switch(glfwGetPlatform()) {
        case GLFW_PLATFORM_WIN32: return 2;    //Windows
        case GLFW_PLATFORM_COCOA: return 1;    //MacOS X
        case GLFW_PLATFORM_WAYLAND:  return 0; //Linux
        case GLFW_PLATFORM_X11: return 0;      //Linux
        default: std::cout << "WARNING: Running on unknown OS"; return 3;
    }

    return 5; //REMOVE
}

void Minecraft::loadScreen() const {
    ScaledResolution scaledResolution(displayWidth, displayHeight);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,
        (double)scaledResolution.scaledWidth,
        (double)scaledResolution.scaledHeight,
        0.0, 1000.0, 3000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0F, 0.0F, -2000.0F);
    glViewport(0, 0, displayWidth, displayHeight);
    glClearColor(0.0F, 0.0F, 0.0F, 0.0F);
    glDisable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glDisable(GL_FOG);
    //glBindTexture(GL_TEXTURE_2D, renderEngine.getTexture("/title/mojang.png"));
}


//TODO: Throw exception

void Minecraft::startGame() {
    if(fullscreen) {
        //TODO Whatever im doing this later
    }

    getOs();
    //Rendermanager.instance.itemRenderer = new ItemRenderer(this); TODO

    //TODO: assign these objects to the declared objects that are currently commented out
    minecraftDir = getAppDir();

    //!PROBLEM I want to do initialize objects class wide.
    this->options = new GameSettings(*this, this->minecraftDir); //TODO
    std::cout << options->mouseSensitivity << "\n";
    this->renderEngine = new RenderEngine(*options);
    std::cout << options->mouseSensitivity << "\n";
    //FontRenderer fontRenderer();

    std::cout << "cbrt Booted Up!";


    while(true) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

