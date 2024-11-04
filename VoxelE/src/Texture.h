#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

namespace Texture
{
    unsigned int loadTexture(char const* path);
    unsigned char* loadDataTexture(char const* path, int width, int height, int nrComponents);

};

