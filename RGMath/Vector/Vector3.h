#include"../Global.h"
#ifdef RGM_VECTOR3
#define RGM_VECTOR3

namespace rgm {
	template<class T>
	class Vector3
	{
	public:
		T x, y, z;
	public:
		RGM_FORCEINLINE Vector3() :
			x(0), y(0), z(0) {};

		RGM_FORCEINLINE Vector3(int a, int b, int c) :
			x(a), y(b), z(c) {};

		RGM_FORCEINLINE Vector3(int val) :
			x(val), y(val), z(val) {};

		RGM_FORCEINLINE Vector3(const Vector3& v) :
			x(v.x), y(v.y), z(v.z) {};

		RGM_FORCEINLINE Vector3& operator = (const Vector3& v) {
			this->x = v.x; this->y = v.y; this->z = v.z;
			return* this;
		}

		RGM_FORCEINLINE bool operator == (const Vector3& v) const {
			return this->x == v.x && this->y == v.y && this->z = v.z;
		}

		RGM_FORCEINLINE Vector3 operator + (const Vector3& v) {
			return Vector3(this->x + v.x, this->y + v.y, this->z + v.z);
		}

		RGM_FORCEINLINE Vector3& operator += (const Vector3& v) {
			this->x += v.x; this->y += v.y; this->z += v.z;
			return *this;
		}

		RGM_FORCEINLINE Vector3 operator - (const Vector3& v) {
			return Vector3(this->x - v.x, this->y - v.y, this->z - v.z);
		}

		RGM_FORCEINLINE Vector3& operator -= (const Vector3& v) {
			this->x -= v.x; this->y -= v.y; this->z -= v.z;
			return *this;
		}

		// Dot product
		RGM_FORCEINLINE Vector3 operator * (const Vector3& v) {
			return Vector3(this->x * v.x, this->y * v.y, this->z * v.z);
		}

		RGM_FORCEINLINE Vector3& operator *= (const Vector3& v) {
			this->x *= v.x; this->y *= v.y; this->z *= v.z;
			return *this;
		}

		// Number multiply
		RGM_FORCEINLINE Vector3 operator * (const T val) {
			return Vector3(this->x * val, this->y * val, this->z * val);
		}

		RGM_FORCEINLINE Vector3& operator *= (const T val) {
			this->x *= val; this->y *= val; this->z *= val;
			return *this;
		}

		friend inline std::ostream& operator << (const std::ostream& os, const Vector3& v) {
			os << "[ " << v.x << ", " << v.y << ", " << v.z << " ]";
			return os;
		}

		// | V | of Vector3
		RGM_FORCEINLINE RG_FLOAT length() {
			return static_cast<RG_FLOAT>(std::sqrtf(std::pow(x, 2), std::pow(y, 2), std::pow(z, 2)));
		}

	};
}

#endif // RGM_VECTOR3

