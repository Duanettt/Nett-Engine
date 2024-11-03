#include "Plane.h"

Plane::Plane() : planeVertices{
    // positions          // texture Coords 
           5.0f, -0.5f,  5.0f,  2.0f, 0.0f,
          -5.0f, -0.5f,  5.0f,  0.0f, 0.0f,
          -5.0f, -0.5f, -5.0f,  0.0f, 2.0f,

           5.0f, -0.5f,  5.0f,  2.0f, 0.0f,
          -5.0f, -0.5f, -5.0f,  0.0f, 2.0f,
           5.0f, -0.5f, -5.0f,  2.0f, 2.0f
}
{
}

void Plane::Init()
{
    glGenVertexArrays(1, &planeVAO);
    glGenBuffers(1, &planeVBO);
    glBindVertexArray(planeVAO);
    glBindBuffer(GL_ARRAY_BUFFER, planeVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(&planeVertices), &planeVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
}

void Plane::Draw(Shader& shader, glm::mat4 projection, glm::mat4& view)
{
    shader.use();
    shader.setMat4("projection", projection);
    shader.setMat4("view", view);
    shader.setMat4("model", planeModelMatrix);
    // Bind and Draw
    glBindVertexArray(planeVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}
