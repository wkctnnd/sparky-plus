#pragma once
static const char* AssetFilePath = "/Assets/";

#define Curve_Component_X "X"
#define Curve_Component_Y "Y"
#define Curve_Component_Z "Z"

#define M_PI 3.14159

enum PropertyType
{
	Translate_Property_Type = 0,
	Scale_Property_Type,
	Rotation_Property_Type,

};

#ifdef UIEXPORT
#define UI_API __declspec(dllexport)
#else UIIMPORT
#define UI_API __declspec(dllimport)
#endif


#ifdef ENGINEEXPORT
#define ENGINE_API __declspec(dllexport)
#else ENGINEIMPORT
#define ENGINE_API __declspec(dllimport)
#endif

