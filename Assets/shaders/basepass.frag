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
 uniform vec4 DiffuseColor;
uniform mat4 world2shadow_matrix;
uniform int isTex;
uniform int isNormalTex;
uniform mat4 shadowvw_matrix;
uniform mat4 shadowpr_matrix;
uniform float uvscale;
uniform vec3 lightdir;
uniform vec3 lightcolor;

 
uniform vec3 pointlightcolor[10];
uniform vec3 pointlightposition[10];
uniform int pointlightcount;

void main()
{
vec3 diffusecolor;
vec2 specialuv = uv;

vec3 n = normalize(cross(dFdx(worldposition), dFdy(worldposition)));

if(isNormalTex==1)
	{
		specialuv = (worldposition.xz+vec2(50.606720,69.70662))/vec2(103.917591,145.470055);
	}
	//specialuv = (worldposition.xz+vec2(50.606720,69.70662))/vec2(103.917591,145.470055);
if(isTex==1)
	diffusecolor = texture2D(diffuseTex, vec2(specialuv.x,specialuv.y) ).xyz;
  else
	diffusecolor.xyz =  DiffuseColor.xyz;
	float shadow = 1;
	vec4 shadowcoord = shadowpr_matrix*shadowvw_matrix*vec4(worldposition.xyz,1);
	//shadowcoord.xyz = shadowcoord.xyz/shadowcoord.w;
	vec2 shadowuv = (shadowcoord.xy+1)/2;
	 shadowcoord.z = (shadowcoord.z+1)/2;
	float shadowvalue = texture2D(shadowTex,vec2(shadowuv.x, shadowuv.y)).x;
	if(shadowcoord.z-0.002>shadowvalue)
		shadow = 0.2;

shadowvalue = 1;
	vec3 normal = worldvertexnormal;
	
	if(isNormalTex==1)
	{
		normal = texture2D(normalMap, vec2(specialuv.x,specialuv.y)).xyz;
		//normal = normalize((normal*2)-1);
	}
		normal = n;
	 
	 vec3 light = vec3(0,10,0);

	 color.xyz = vec3(0,0,0);
	 for(int i=0;i<pointlightcount;i++)
	 {
		 vec3 dir = -normalize(worldposition - pointlightposition[i]);
		 	 vec3 lenvec = (worldposition-light)/100;
			 float lensqure = dot(lenvec,lenvec);
	float nl = clamp(dot(normalize(dir),normal),0,1);
	vec3 specular = vec3(0.1,0.0,0.0)* pow(nl,20)/lensqure;

	
	//color.xyzw   += 0.1;
	color.xyz   +=  pointlightcolor[i] * diffusecolor * vec3(nl,nl,nl);
	 }
	

 float nl = clamp(dot(normalize(lightdir),normal),0,1);
	//vec3 specular = vec3(0.3,0.3,0.3)* pow(nl,20);
	//vec4 shadowcoord = world2shadow_matrix*vec4(worldposition,1) ;
	//shadowcoord.xy = (shadowcoord.xy/shadowcoord.w+1)/2;
	//float shadow = texture2D(shadowTex, shadowcoord.xy).x;
	
	color.xyz   += vec3(0.2,0.2,0.2)*shadow * diffusecolor * ((vec3(nl,nl,nl)+vec3(0.2,0.2,0.2)));

	


	color.w = 1;
}