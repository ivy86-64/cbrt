cmake_minimum_required(VERSION 3.29)
project(MinecraftTranslated)

set(CMAKE_CXX_STANDARD 20)

INCLUDE_DIRECTORIES(Headers/
                    Libraries/)

add_executable(MinecraftTranslated main.cpp
        Core/Minecraft.cpp
        Core/Minecraft.h
        Libraries/glad.c
        Renderer/RenderEngine.cpp
        Renderer/RenderEngine.h
        Renderer/FontRenderer.cpp
        Renderer/FontRenderer.h
        Core/GameSettings.cpp
        Core/GameSettings.h
        Renderer/ScaledResolution.cpp
        Renderer/ScaledResolution.h

)

#Add GLFW
find_package(glfw3 3.3 REQUIRED)
find_package(glm REQUIRED)
target_link_libraries(MinecraftTranslated glfw config++ glm::glm)

#Make GLFW work on linux
add_link_options(-lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lconfig++)
