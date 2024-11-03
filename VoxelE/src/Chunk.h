#pragma once

#include "Block.h"

#include <vector>
#include <iostream>

#define CHUNK_SIZE 5

class Chunk
{
public:
	Chunk();
	void Draw(Shader& shader, glm::mat4 projection, glm::mat4& view);

private:
	std::vector<Block> blocks;
};

