#pragma once
#include"../Global.h"
#ifdef RGM_VECTOR3
#define RGM_VECTOR3

namespace rgm {
	template<class T>
	class RGM_API Vector3
	{
	private:
		union {
			struct { T x, y, z; };
			struct { T r, g, b; };
			struct { T x1, x2, x3; };
		};
	public:
		RGM_FORCEINLINE Vector3() 
			: x(0), y(0), z(0) {};

		RGM_FORCEINLINE Vector3(T a, T b, T c) 
			: x(a), y(b), z(c) {};

		RGM_FORCEINLINE Vector3(T val) 
			: x(val), y(val), z(val) {};

		RGM_FORCEINLINE Vector3(const Vector3& v) 
			: x(v.x), y(v.y), z(v.z) {};

		RGM_FORCEINLINE Vector3& operator = (const Vector3& v) {
			this->x = v.x; this->y = v.y; this->z = v.z;
			return* this;
		}

		RGM_FORCEINLINE bool operator == (const Vector3& v) const {
			return this->x == v.x && this->y == v.y && this->z == v.z;
		}

		RGM_FORCEINLINE Vector3 operator + (const Vector3& v) const {
			return Vector3(this->x + v.x, this->y + v.y, this->z + v.z);
		}

		RGM_FORCEINLINE Vector3& operator += (const Vector3& v) {
			this->x += v.x; this->y += v.y; this->z += v.z;
			return *this;
		}

		RGM_FORCEINLINE Vector3 operator - (const Vector3& v) const {
			return Vector3(this->x - v.x, this->y - v.y, this->z - v.z);
		}

		RGM_FORCEINLINE Vector3& operator -= (const Vector3& v) {
			this->x -= v.x; this->y -= v.y; this->z -= v.z;
			return *this;
		}

		// Dot product
		RGM_FORCEINLINE Vector3 operator * (const Vector3& v) const {
			return Vector3(this->x * v.x, this->y * v.y, this->z * v.z);
		}

		RGM_FORCEINLINE Vector3& operator *= (const Vector3& v) {
			this->x *= v.x; this->y *= v.y; this->z *= v.z;
			return *this;
		}

		// Right number multiply
		template <typename num>
		RGM_FORCEINLINE Vector3 operator * (const num& val) const noexcept {
			return Vector3(this->x * val, this->y * val, this->z * val);
		}

		template <typename num>
		RGM_FORCEINLINE Vector3& operator *= (const num& val) const noexcept{
			this->x *= val; this->y *= val; this->z *= val;
			return *this;
		}

		// Left number multiply
		template <typename num>
		friend RGM_FORCEINLINE Vector3 operator * (const num& val, Vector3& v) {
			return v * val;
		}

		RGM_FORCEINLINE T operator [] (int idx) {
			if (idx > 3 || idx < 1) throw "Illegal argument";
			return idx == 1 ? this->x : idx == 2 ? this->y : this->z;
		}

		static RGM_FORCEINLINE Vector3<T> Zeros() {
			return Vector3<T>();
		}

		// | V | of Vector3
		RGM_FORCEINLINE RG_FLOAT length() {
			return static_cast<RG_FLOAT>(std::sqrtf(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2)));
		}

		friend inline std::ostream& operator << (std::ostream& os, const Vector3& v) {
			os << "[ " << v.x << ", " << v.y << ", " << v.z << " ]" << std::endl;
			return os;
		}

	};
}

#endif // RGM_VECTOR3

