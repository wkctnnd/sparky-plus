#version 450 core

uniform mat4 pr_matrix;

uniform mat4 vw_matrix;


layout(location = 0) in vec3 position;
layout (location = 0) out vec4 worldPos;


void main()
{
 
    gl_Position = pr_matrix  * vw_matrix * vec4(position.xyz, 1.0);
	worldPos =  vec4(position.xyz, 1.0);
}



















