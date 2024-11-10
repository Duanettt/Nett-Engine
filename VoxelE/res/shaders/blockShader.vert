#version 330 core

// Vertex attributes
layout (location = 0) in vec3 aPos;        // Vertex position
layout (location = 1) in vec3 aNormal;     // Normal position

// Instanced attributes (each instance matrix is represented as 4 vec4)
layout (location = 2) in mat4 instanceModel;
// Uniforms
uniform mat4 view;
uniform mat4 projection;

// Outputs to fragment shader
out vec2 TexCoords;

out vec3 FragPos;
out vec3 Normal;

void main()
{
    // Apply the projection, view, and instance model transformations
    gl_Position = projection * view * instanceModel * vec4(aPos, 1.0f);
    
    // Pass the texture coordinates to the fragment shader
    // Frag Position sent to the fragment shader
    FragPos = vec3(instanceModel * vec4(aPos, 1.0));
    // Normals sent to the fragment position
    Normal = aNormal;
}
