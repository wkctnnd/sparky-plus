#version 330 core

 
 varying vec3 worldposition;
 varying vec2 uv;
 varying vec3 clipposition;
 varying vec4 intorcolor;
layout (location = 0) out vec4 color;

 varying vec3 worldvertexnormal;
  uniform vec3 ScaleColor;
 uniform sampler2D diffuseTex;
 uniform sampler2D shadowTex;
 uniform sampler2D normalMap;
uniform mat4 world2shadow_matrix;
uniform int isTex;
uniform int isNormalTex;
uniform mat4 shadowvw_matrix;
uniform mat4 shadowpr_matrix;
uniform float uvscale;
void main()
{
vec3 diffusecolor;
vec2 specialuv = uv;
if(isNormalTex==1)
	{
		specialuv = (worldposition.xz+vec2(50.606720,69.70662))/vec2(103.917591,145.470055);
	}
	//specialuv = (worldposition.xz+vec2(50.606720,69.70662))/vec2(103.917591,145.470055);
if(isTex==1)
	diffusecolor = texture2D(diffuseTex, vec2(specialuv.x,specialuv.y) ).xyz;
  else
	diffusecolor =  intorcolor.xyz;
	float shadow = 1;
	vec4 shadowcoord = shadowpr_matrix*shadowvw_matrix*vec4(worldposition.xyz,1);
	//shadowcoord.xyz = shadowcoord.xyz/shadowcoord.w;
	vec2 shadowuv = (shadowcoord.xy+1)/2;
	 shadowcoord.z = (shadowcoord.z+1)/2;
	float shadowvalue = texture2D(shadowTex,vec2(shadowuv.x, shadowuv.y)).x;
	if(shadowcoord.z-0.001>shadowvalue)
		shadow = 0.4;


	vec3 normal = worldvertexnormal;
	if(isNormalTex==1)
	{
		normal = texture2D(normalMap, vec2(specialuv.x,specialuv.y)).xyz;
		//normal = normalize((normal*2)-1);
	}
		
	 vec3 light = normalize(vec3(10,10,10));
	float nl = clamp(dot(light,normal),0,1);
	vec3 specular = vec3(0.3,0.3,0.3)* pow(nl,20);
	//vec4 shadowcoord = world2shadow_matrix*vec4(worldposition,1) ;
	//shadowcoord.xy = (shadowcoord.xy/shadowcoord.w+1)/2;
	//float shadow = texture2D(shadowTex, shadowcoord.xy).x;
	
	color.xyz  = (specular+diffusecolor*nl)*shadow;
	//color =  color+vec4(0.1,0.1,0.1,0);
    //color.xyz=vec3(specialuv.y,0,0);
	//color.z=0;

}