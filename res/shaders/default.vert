#version 330 core

layout(location = 0) in vec3 iPosition;
layout(location = 1) in vec3 iColor;

out vec3 color;

void main() {
	gl_Position.xyz = iPosition;
	gl_Position.w = 1;
	
	color = iColor;
}