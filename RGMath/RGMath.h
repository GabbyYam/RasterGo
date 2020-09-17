// For use of RGMath
#define RG_WINDOWS
#define RG_MATH
#ifdef RG_WINDOWS
	#ifdef RG_MATH
		#define RGM_API __declspec(dllexport)
	#else
		#define RGM_API __declspec(dllimport)
	#endif
#else
	#error Win Only!
#endif

#include"Global.h"
#include"Matrix/BaseMatrix.h"
#include"Matrix/Matrix3.h"
#include"Matrix/Matrix4.h"
#include"Vector/Vector2.h"
#include"Vector/Vector3.h"
#include"Vector/Vector4.h"

namespace rgm {
	typedef Vector2<float> Vector2f;
	typedef Vector2<int>   Vector2i;

	typedef Vector3<float> Vector3f;
	typedef Vector3<int>   Vector3i;

	typedef Vector4<float> Vector4f;
	typedef Vector4<int>   Vector4i;

	typedef Matrix3<float> Matrix3f;
	typedef Matrix3<int>   Matrix3i;
};