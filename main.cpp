#include <chrono>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Core/Minecraft.h"

void startMainThread(std::string_view playerName, std::string_view unkwnVar2) {
    bool unkwnBool3 = false;

    constexpr int width = 854;
    constexpr int height = 480;

    if(!glfwInit()) {
        std::cout << "Failed to init GLFW.";
        exit(EXIT_FAILURE);
    }

    printf("Compiled against GFLW %i.%i.%i\n", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);

    GLFWwindow* window = glfwCreateWindow(width, height, "Minecraft Translated To C++ by ivyyx86", NULL, NULL);
    if(!window) {
        std::cout << "Failed to create Window";
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);

    gladLoadGL();
    fprintf(stderr, "OpenGL %s\n", glGetString(GL_VERSION));

    glViewport(0, 0, width, height);


    Minecraft minecraftGame(window, width, height, false);

    minecraftGame.startGame();
}

int main(int argc, char* argv[]) {
    std::string playerName = "Player" + std::to_string(clock() % 1000);

    if(argv[1] != nullptr) {
        playerName = argv[1];
    }

    std::string unkwnString2 = "-";
    if(argv[2] != nullptr) {
        unkwnString2 = argv[2];
    }

    std::cout << "Set Player Name: " << playerName << '\n';

    startMainThread(playerName, unkwnString2);

}
