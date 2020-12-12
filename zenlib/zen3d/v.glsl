#version 330 core

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec4 inColour;

out vec4 fColour;

void main() {
    gl_Position = vec4(inPosition, 1.0);
    fColour = inColour;
}
