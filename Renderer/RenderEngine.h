//
// Created by madeline on 25.10.24.
//

#ifndef RENDERENGINE_H
#define RENDERENGINE_H

#include "../Core/GameSettings.h"

class GameSettings;

class RenderEngine {

private:
    //!PROBLEM here is the delcaration for another class
    GameSettings &options;
    //HashMap textureMap = new HashMap(); TODO
    //HashMap textureContentsMap = new MashMap(); TODO
    //IntBuffer singleIntBuffer = GLAllocation.createDirectIntBuffer(1);
    //ByteBuffer imageData = GLAllocation.createDirectByteBuffer(1048576);
    //List textureList = new ArrayList();
    //Map urlToImageDataMap = new HashMap();
    bool clampTexture = false;
public:
    bool useMipmaps = false;
    int getTexture(std::string texFile) const;

    //!here i also wanna have a object from the Minecraft class be available class-wide as a pointer, so that if i change something here it will update in the mincerfat class
    RenderEngine(GameSettings &options) : options(options){

        this->options.mouseSensitivity = 6.9F;
        //this->options = options;
    }
};



#endif //RENDERENGINE_H
