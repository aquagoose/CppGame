#version 330 core

layout (location = 0) in vec2 aPosition;
layout (location = 1) in vec2 aTexCoords;

out vec2 frag_texCoords;

uniform mat4 uCamera;

void main()
{
    gl_Position = uCamera * vec4(aPosition, 0.0, 1.0);
    frag_texCoords = aTexCoords;
}