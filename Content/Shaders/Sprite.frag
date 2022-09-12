#version 330 core

in vec2 frag_texCoords;
in float frag_mipLevel;

out vec4 out_color;

uniform sampler2D uTexture;

void main()
{
    out_color = textureLod(uTexture, frag_texCoords, frag_mipLevel);
}