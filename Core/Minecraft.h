//
// Created by madeline on 25.10.24.
//

#ifndef MINECRAFT_H
#define MINECRAFT_H
#include <string>
#include <filesystem>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../Renderer/RenderEngine.h"
#include "GameSettings.h"

class RenderEngine;
class GameSettings;

class Minecraft {
private:
    bool fullscreen = false;
    // OpenGlCapsChecker glCapabilities; TODO
    // Timer timer = new Timer(20.0F) TODO
    // ThreadDownloadResources downloadResourcesThread; TODO
    int tickRan = 0;
    int leftClickCounter = 0;
    int tempDisplayWidth{};
    int tempDisplayHeight{};
    std::string serverName;
    int serverPort{};
    //TextureWaterFX textureWaterFX = new TextureWaterFX();
    //TextureLavaFX textureLavaFX = new TextureLavaFX();
    std::filesystem::path minecraftDir;
    int mouseTicksRan = 0;

    //!PROBLEM Here are the declarations
    GameSettings *options;
    RenderEngine *renderEngine;

public:

    Minecraft(GLFWwindow *window, int width, int height, bool fullscreen) {

        tempDisplayWidth = width;
        tempDisplayHeight = height;
        Minecraft::window = window;
        //TODO find out what ThreadSleepForever(this, "Timer hack thread") is and implement

        displayWidth = width;
        displayHeight = height;
        Minecraft::fullscreen = fullscreen;
    }
    //public PlayerController playerController; TODO
    int displayWidth{};
    int displayHeight{};
    //World theWorld TODO
    //RenderGlobal renderGlobal TODO
    //EntityPlayerSP thePlayer TODO
    //EffectRenderer effectRenderer TODO
    //Session session = null TODO
    std::string minecraftUri;
    GLFWwindow *window;
    //boolean appletMode = true; TODO
    volatile bool isGamePaused = false;
    //public FontRenderer fontRenderer TODO
    //public GuiScreen currentScreen = null; TODO
    //public LoadingScreenRenderer loadingScreen = new LoadingScreenRenderer(this); TODO
    //public EntityRenderer entityRenderer = new EntityRenderer(this); TODO
    std::string loadMapUser;
    int loadMapID = 0;
    //GuiIngame ingameGUI; TODO
    bool skipRenderWorld = false;
    //ModelBiped playerModelBiped = new ModelBiped(0.0F) TODO
    //MovingObjectPosition objectMouseOver = null; TODO
    //!PROTECTED! MinecraftApplet mcApplet TODO
    //public SoundManager sndManager = new SoundManager(); TODO
    //MouseHelper mouseHelper TODO
    //std::string mcDataDir;
    static long frameTimes[512];
    static int numRecordedFrameTimes;
    volatile bool running = true;
    std::string debug;
    long prevFrameTime = -1L;
    bool inGameHasFocus = false;
    bool isRaining = false;
    //long systemTime = clock(); TODO
    int joinPlayerCounter = 0;

    //FUNCTIONS
    void run();

    static std::filesystem::path getAppDir();
    void startGame();

    static int getOs();
    void loadScreen() const;
};



#endif //MINECRAFT_H
