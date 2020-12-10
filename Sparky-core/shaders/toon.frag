#version 450 core

 
 varying vec3 worldposition;
layout (location = 0) out vec4 color;
 



void main()
{
	vec3 n = normalize(cross(dFdx(worldposition), dFdy(worldposition)));
	 vec3 light = normalize(vec3(0,1,1));
	float nl = clamp(dot(light,-n),0,1);
	color =  vec4(nl,nl,nl,1);
	

}