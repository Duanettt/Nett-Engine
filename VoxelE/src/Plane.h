#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include  "Shader.h"

class Plane
{
public:
	Plane();

	void Init();

	void Draw(Shader& shader, glm::mat4 projection, glm::mat4& view);

private:
	unsigned int planeVAO, planeVBO;

	glm::mat4 planeModelMatrix;

	float planeVertices[30]; 
};

