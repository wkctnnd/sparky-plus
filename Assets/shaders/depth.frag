#version 450 core


uniform  vec3 center;

layout (location = 0) out vec4 color;
varying vec3 worldposition;
 varying vec4 clippos;



void main()
{
	vec3 l = worldposition - center;
	float length  = sqrt(l.x*l.x+l.y*l.y+l.z*l.z);
 
	color = vec4(clippos.z/clippos.w,clippos.z/clippos.w,clippos.z/clippos.w,1) ;
	  

}























