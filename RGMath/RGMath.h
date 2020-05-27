// For use of RGMath

#ifdef RG_WINDOWS
	#ifdef RG_MATH
		#define RGM_API __declspec(dllimport)
	#else
		#define RGM_API __declspec(dllexport)
	#endif
#else
	#error Only support window platform
#endif

#include"Global.h"
#include"Matrix/Matrix3.h"
#include"Vector/Vector2.h"
#include"Vector/Vector3.h"