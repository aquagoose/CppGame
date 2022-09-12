//
// Created by ollie on 12/09/22.
//

#include "Scene.h"
#include <iostream>

namespace Engine
{
    Scene::~Scene()
    {
        std::cout << "Scene destructor called." << std::endl;
    }
} // Engine