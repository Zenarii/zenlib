@vertex
#version 330 core

layout(location = 0) in vec2 inPosition;
layout(location = 1) in vec2 inTextureCoords;

out vec2 fTextureCoords;

void main() {
    gl_Position = vec4(inPosition.x, inPosition.y, 0.0, 1.0);
    fTextureCoords = inTextureCoords;
}

@fragment
#version 330 core

in vec2 fTextureCoords;
uniform sampler2D ScreenTexture;

out vec4 FragColour;

void main() {
    FragColour = texture(ScreenTexture, fTextureCoords);
}