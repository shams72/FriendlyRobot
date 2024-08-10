#version 330 core

layout (location = 0) in vec3 pos; // Updated to accept a 3D vertex position
layout (location = 1) in vec3 colorRGB;

out vec3 colorVS;

uniform mat4 modelMatrix;

uniform mat4 view;
uniform mat4 projection;


void main(){
    colorVS = colorRGB;
    gl_Position = projection*view*modelMatrix*vec4(pos, 1.0); // Set the vertex position as is, with the w-coordinate as 1.0
}
