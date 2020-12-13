#version 330 core

 
 varying vec3 worldposition;
 varying vec3 worldnormal;
layout (location = 0) out vec4 color;
 uniform vec3 DiffuseColor;
 uniform vec3 camerapos;


void main()
{
	 vec3 rimlight = normalize(camerapos - worldposition);
	float rim = 1 - clamp(abs(dot(rimlight, worldnormal)),0,1);
	vec3 rimcolor = vec3(20,20,20)*pow(rim, 10);
	 vec3 light = normalize(vec3(10,10,0));
	float nl = clamp(dot(light,worldnormal),0,1);

	nl=(nl+1)/2;
			nl=smoothstep(0,1,nl);
			
			float toon=floor(nl*3)/3;

	color.xyz = DiffuseColor*toon+rimcolor;

	color =  color ;

}