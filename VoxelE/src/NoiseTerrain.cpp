#include "NoiseTerrain.h"

NoiseTerrain::NoiseTerrain()
{

	myNoise.SetFrequency(0.2);
	myNoise.SetOctaveCount(4);
	myNoise.SetPersistence(0.5);
	myNoise.SetLacunarity(1.8);

	float scale = 0.5f;

	// Loop over the horizontal (x, z) coordinates only
// Loop over the horizontal (x, z) coordinates only
	for (int x = 0; x < CHUNK_SIZE; x++)
	{
		for (int z = 0; z < CHUNK_SIZE; z++)
		{
			// Get the noise value for the current (x, z) location to determine height
			double noiseValue = GenerateNoise(x, 0, z); // Sample noise only in the x-z plane
			//std::cout << "Noise Value at (" << x << ", " << z << "): " << noiseValue << std::endl;

			// Map the noise value to a suitable height range within CHUNK_SIZE
			int height = static_cast<int>((noiseValue + 1.0) * 0.5 * CHUNK_SIZE);

			// Place blocks up to the calculated height
			for (int y = 0; y < height; y++)
			{
				// Set the position for each block at this (x, y, z) location
				glm::vec3 position(x * scale, y * scale, z * scale);
				glm::mat4 modelMatrix(1.0f);
				modelMatrix = glm::translate(modelMatrix, position);
				modelMatrix = glm::scale(modelMatrix, glm::vec3(scale));
				modelMatrices.push_back(modelMatrix);
			}
		}
	}


	std::cout << modelMatrices.size() << std::endl;

	//for (size_t i = 0; i < modelMatrices.size(); i++) {
	//	glm::mat4 matrix = modelMatrices[i];
	//	std::cout << "Matrix " << i << ": " << glm::to_string(matrix) << std::endl;
	//}

	block.InitInstanced(modelMatrices);
}


NoiseTerrain::NoiseTerrain(bool normalTerrain)
{

	myNoise.SetFrequency(0.5);
	myNoise.SetOctaveCount(3);
	myNoise.SetPersistence(0.4);
	myNoise.SetLacunarity(1.5);  // Lacunarity controls the frequency of the noise

	float scale = 0.5f;

	// Loop over the horizontal (x, z) coordinates only
	for (int x = 0; x < CHUNK_SIZE; x++)
	{
		for (int z = 0; z < CHUNK_SIZE; z++)
		{
			// Get the noise value for the current (x, z) location to determine height
			double noiseValue = GenerateNoise(x, 0, z); // Sample noise only in the x-z plane

			// Map the noise value to a suitable height range within CHUNK_SIZE
			int height = static_cast<int>((noiseValue + 1.0) * 0.5 * CHUNK_SIZE);

			// Place blocks up to the calculated height
			for (int y = 0; y < height; y++)
			{
				Block block;
				block.Init();

				// Set the position for each block at this (x, y, z) location
				glm::vec3 position(x * scale, y * scale, z * scale);
				block.SetPosition(position);
				block.SetScale(scale);

				// Add the block to the list
				blocks.push_back(block);
			}
		}
	}
}


void NoiseTerrain::GenerateTerrain(Shader& shader, glm::mat4 projection, glm::mat4& view)
{
	for (Block block : blocks)
	{
		block.Draw(shader, projection, view);
	}
}

void NoiseTerrain::GenerateTerrainInstanced(Shader& shader, glm::mat4 projection, glm::mat4& view)
{
	block.DrawInstanced(shader, projection, view, modelMatrices.size());
}

double NoiseTerrain::GenerateNoise(double x, double y, double z)
{
	// Assuming y is 0 since we're sampling in 2D
	return myNoise.GetValue(x * 0.1, 0.0 , z * 0.1); // Scale x and z for a better distribution
}
