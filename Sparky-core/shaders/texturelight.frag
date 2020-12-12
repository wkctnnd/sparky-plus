#version 450 core

 varying vec3 worldnormal;
 varying vec3 worldposition;
 varying vec2 uv;
layout (location = 0) out vec4 color;
 

 uniform sampler2D tex;
 


void main()
{
 vec3 diffusecolor = texture2D(tex, vec2(uv.x,1-uv.y)).xyz;
	 vec3 light = normalize(vec3(10,10,0));
	float nl = clamp(dot(light,worldnormal),0,1);

	color.xyz = diffusecolor*nl;
	color =  color+vec4(0.1,0.1,0.1,0);;
	

}