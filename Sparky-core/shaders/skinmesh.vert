#version 450 core

uniform mat4 pr_matrix;

uniform mat4 vw_matrix;
uniform mat4 BoneMatrix[30];

layout(location = 0) in vec3 position;
layout(location = 1) in vec4 BoneWeight;
layout(location = 2) in ivec4 BoneIndex;

varying vec3 worldposition;
varying mat4 temp;
varying ivec4 temp2;
varying vec4 temp3;

void main()
{
 
   vec4 pos = vec4(position.x,position.y,position.z,1);

	mat4 FinalMatrix = (BoneWeight.x * BoneMatrix[BoneIndex.x] + BoneWeight.y*BoneMatrix[BoneIndex.y] + BoneWeight.z*BoneMatrix[BoneIndex.z] + BoneWeight.w*BoneMatrix[BoneIndex.w])/4;
	gl_Position = pr_matrix  * vw_matrix  * FinalMatrix*pos;
	
	worldposition = position;
	temp = FinalMatrix;
	temp2 = BoneIndex;
	temp3 = BoneWeight;
}



















