#pragma once

#define CHUNK_SIZE 150

#include "Block.h"

#include <vector>

#include <noise/noise.h>

class NoiseTerrain
{
public:
	NoiseTerrain();

	NoiseTerrain(bool normalTerrain);

	void GenerateTerrain(Shader& shader, glm::mat4 projection, glm::mat4& view);

	void GenerateTerrainInstanced(Shader& shader, glm::mat4 projection, glm::mat4& view);

	double GenerateNoise(double x, double y, double z);

	Block block;

private:
	noise::module::Perlin myNoise;
	std::vector<Block> blocks;
	std::vector<glm::vec3> voxelPositions;

	unsigned int modelMatrixBuffer;
	std::vector<glm::mat4> modelMatrices;
};

