#pragma once
#include <cstdlib>
 
static const char* AssetFilePath = "/../Assets/";
#define  MEMORY_DEBUG

#ifdef MEMORY_DEBUG
	
void *operator new(size_t size)
{

}


void operator delete(void* ptr)
{

}

#endif


#define Curve_Component_X "X"
#define Curve_Component_Y "Y"
#define Curve_Component_Z "Z"

enum PropertyType
{
	Translate_Property_Type = 0,
	Scale_Property_Type,
	Rotation_Property_Type,

};
