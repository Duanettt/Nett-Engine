#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

#include "Shader.h"

#include <vector>

class Block
{
public:
	Block();

	void Init();

	void InitInstanced(std::vector<glm::mat4> modelMatrices);


	void SetPosition(glm::vec3 blockPosition);

	void SetScale(float scale);

	void Draw(Shader& shader, glm::mat4 projection, glm::mat4& view);

	void DrawInstanced(Shader& shader, glm::mat4 projection, glm::mat4& view, int instanceCount);


private:
	unsigned int VAO, VBO;

	glm::mat4 blockModel = glm::mat4(1.0f);

	float cubeVertices[216];

};

