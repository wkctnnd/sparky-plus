#version 450 core


 varying vec3 worldnormal;
 varying vec3 worldposition;
layout (location = 0) out vec4 color;
 



void main()
{
	//vec3 n = normalize(cross(dFdx(worldposition), dFdy(worldposition)));
	vec3 n = vec3(0,1,0);
	float nl = dot(n,-worldnormal);
	color = vec4(-worldnormal,1) ;
	

}























