#version 450 core

uniform mat4 pr_matrix;

uniform mat4 view_matrix;
uniform mat4 world_matrix;


layout(location = 0) in vec3 position;
 layout(location = 1) in vec3 normal;
  layout(location = 2) in vec2 texcoord;
varying vec3 worldposition;
varying vec3 worldnormal;
varying vec2 uv;
void main()
{
 

	mat4 vw_matrix = view_matrix * world_matrix;
    gl_Position = pr_matrix  * vw_matrix * vec4(position.xyz, 1.0);


	worldnormal = normal;
	worldposition = position;
	uv = texcoord;

}



















