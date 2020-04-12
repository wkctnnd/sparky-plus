#version 450 core

uniform mat4 pr_matrix;

uniform mat4 vw_matrix;
uniform mat4 BoneMatrix[30];

layout(location = 0) in vec3 position;
layout(location = 1) in vec4 BoneWeight;
layout(location = 2) in int4 BoneIndex;
varying vec3 worldposition;


void main()
{
 
   

	mat4 FinalMatrix = (BoneWeight[0] * BoneMatrix[BoneIndex[0]] + BoneWeight[1]*BoneMatrix[BoneIndex[1]]] + BoneWeight[2]*BoneMatrix[BoneIndex[2]]] + BoneWeight[3]*BoneMatrix[BoneIndex[3]])/4;
	gl_Position = pr_matrix  * vw_matrix * FinalMatrix * vec4(position.xyz, 1.0);
	
	worldposition = position;
}



















