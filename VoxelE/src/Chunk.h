#pragma once

#include "Block.h"

#include <vector>
#include <iostream>

#define CHUNK_SIZE 150

class Chunk
{
public:
	Chunk();
	void CreateCubeChunk();
	void CreateSphereChunk();
	void CreateSphereChunkInstanced();
	void Draw(Shader& shader, glm::mat4 projection, glm::mat4& view);

	void DrawInstanced(Shader& shader, glm::mat4 projection, glm::mat4& view);

	Block block;

private:
	std::vector<Block> blocks;
	std::vector<glm::mat4> modelMatrices;
};

