#pragma once

#define CHUNK_SIZE 75

#include "Block.h"

#include <vector>

#include <noise/noise.h>

class NoiseTerrain
{
public:
	NoiseTerrain();

	void GenerateTerrain(Shader& shader, glm::mat4 projection, glm::mat4& view);

	double GenerateNoise(double x, double y, double z);

private:
	noise::module::Perlin myNoise;
	std::vector<Block> blocks;
	std::vector<glm::vec3> voxelPositions;
};

