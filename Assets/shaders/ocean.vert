#version 450 core

uniform mat4 pr_matrix;

uniform mat4 vw_matrix;


layout(location = 0) in vec3 position;
 

varying vec3 worldposition;


void main()
{
 
   vec4 pos = vec4(position.x,position.y,position.z,1);
    
	gl_Position = pr_matrix  * vw_matrix  *pos;
	
	worldposition = position;


}



















