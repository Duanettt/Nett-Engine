#include "Chunk.h"

Chunk::Chunk()
{

}

void Chunk::CreateCubeChunk()
{
	for (int x = 0; x < CHUNK_SIZE; x++)
	{
		for (int y = 0; y < CHUNK_SIZE; y++)
		{
			for (int z = 0; z < CHUNK_SIZE; z++)
			{
				Block block;

				block.Init();

				// Pass it in as a variable for chunks when we draw
				float scale = 0.2;

				glm::vec3 position(x * scale, y * scale, z * scale);

				block.SetPosition(position);
				block.SetScale(scale);

				blocks.push_back(block);
			}
		}
	}
}

void Chunk::CreateSphereChunk()
{
		for (int z = 0; z < CHUNK_SIZE; z++) {
			for (int y = 0; y < CHUNK_SIZE; y++) {
				for (int x = 0; x < CHUNK_SIZE; x++) {
					if (sqrt((float)(x - CHUNK_SIZE / 2) * (x - CHUNK_SIZE / 2) + (y - CHUNK_SIZE / 2) * (y - CHUNK_SIZE / 2) + (z - CHUNK_SIZE / 2) * (z - CHUNK_SIZE / 2)) <= CHUNK_SIZE / 2) {
						Block block;

						block.Init();

						float scale = 0.2f;

						glm::vec3 position(x * scale, y * scale, z * scale);

						block.SetPosition(position);

						block.SetScale(scale);

						blocks.push_back(block);
					}
				}
			}
		}
}

void Chunk::Draw(Shader& shader, glm::mat4 projection, glm::mat4& view)
{
	for(Block block : blocks)
	{
		block.Draw(shader, projection, view);
	}
}



