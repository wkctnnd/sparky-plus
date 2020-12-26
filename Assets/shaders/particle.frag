#version 450 core


uniform  vec3 center;

layout (location = 0) out vec4 color;
varying vec3 worldposition;
 



void main()
{
	vec3 l = worldposition - center;
	float length  = sqrt(l.x*l.x+l.y*l.y+l.z*l.z);
	//if(length>0.1) color = vec4(0,0,0,0);
	//else
	color = vec4(length/4,0,0,0.5) ;
	

}























