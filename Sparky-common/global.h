#pragma once

#ifdef UIEXPORT
#define UI_API __declspec(dllexport)
#else UIIMPORT
#define UI_API __declspec(dllimport)
#endif



