#version 450 core

uniform mat4 pr_matrix;

uniform mat4 vw_matrix;


layout(location = 0) in vec3 position;

varying vec3 worldposition;

void main()
{
 
    gl_Position = pr_matrix  * vw_matrix * vec4(position.xyz, 1.0);

	worldposition = position;
}



















