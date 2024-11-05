#version 330 core

// Vertex attributes
layout (location = 0) in vec3 aPos;        // Vertex position
layout (location = 1) in vec2 aTexCoords;  // Texture coordinates

// Instanced attributes (each instance matrix is represented as 4 vec4)
layout (location = 2) in mat4 instanceModel;
// Uniforms
uniform mat4 view;
uniform mat4 projection;

// Outputs to fragment shader
out vec2 TexCoords;

void main()
{
    // Apply the projection, view, and instance model transformations
    gl_Position = projection * view * instanceModel * vec4(aPos, 1.0f);
    
    // Pass the texture coordinates to the fragment shader
    TexCoords = aTexCoords;
}
