#version 330 core

uniform mat4 pr_matrix;

uniform mat4 view_matrix;
uniform mat4 world_matrix;


layout(location = 0) in vec3 position;
 layout(location = 1) in vec3 normal;
  layout(location = 2) in vec2 texcoord;
  layout(location = 3) in vec4 vertexcolor;
varying vec3 worldposition;
varying vec3 worldvertexnormal;
varying vec4 intorcolor;

varying vec2 uv;
 //varying vec4 clipposition;
void main()
{
 

	mat4 vw_matrix = view_matrix * world_matrix;
    gl_Position = pr_matrix  * vw_matrix * vec4(position.xyz, 1.0);


	worldvertexnormal = mat3(world_matrix)*normal;
	worldposition.xyz = (world_matrix* vec4(position,1)).xyz;
	uv = texcoord;
	intorcolor = vertexcolor;
	//clipposition = gl_Position;
}



















