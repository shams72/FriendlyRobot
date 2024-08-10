#version 330 core

in vec3 colorVS;

//fragment shader output
out vec4 color;

uniform float colorx;
uniform float colory;
uniform float colorz;





void main(){

    color = vec4(colorVS.x*colorx, colorVS.y*colory, colorVS.z*colorz, 1.0);

}

