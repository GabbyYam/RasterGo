#pragma once
#include"../Global.h"
#ifdef  RGM_VECTOR4
#define RGM_VECTOR4
namespace rgm {
	enum VType {
		RV, CV
	};
	template<class T, VType = RV>
	class RGM_API Vector4 {
	public:
		struct {
			T x1, x2, x3, x4;
		};

	public:
		RGM_FORCEINLINE Vector4() 
			: x1(0), x2(0), x3(0), x4(0) {};

		RGM_FORCEINLINE Vector4(T val) 
			: x1(val), x2(val), x3(val), x4(val) {};

		RGM_FORCEINLINE Vector4(T v1, T v2, T v3, T v4)
			: x1(v1), x2(v2), x3(v3), x4(v4) {};

		RGM_FORCEINLINE Vector4(const Vector4& v)
			: x1(v.x1), x2(v.x2), x3(v.x3), x4(v.x4) {};

		RGM_FORCEINLINE Vector4& operator = (const Vector4& v) {
			this->x1 = v.x1; this->x2 = v.x2;
			this->x3 = v.x3; this->x4 = v.x4;
			return *this;
		}

		RGM_FORCEINLINE bool operator == (const Vector4& v) const {
			return this->x1 == v.x1 && this->x2 == v.x2 &&
				this->x3 == v.x3 && this->x4 == v.x4;
		}

		RGM_FORCEINLINE Vector4 operator + (const Vector4& v) const {
			return Vector4(this->x1 + v.x1,
						   this->x2 + v.x2,
						   this->x3 + v.x3,
						   this->x4 + v.x4);
		}

		RGM_FORCEINLINE Vector4& operator += (const Vector4& v) {
			this->x1 += v.x1; this->x2 += v.x2;
			this->x3 += v.x3; this->x4 += v.x4;
			return *this;
		}

		RGM_FORCEINLINE Vector4 operator - (const Vector4& v) const {
			return Vector4(this->x1 - v.x1,
						   this->x2 - v.x2,
						   this->x3 - v.x3,
						   this->x4 - v.x4);
		}

		RGM_FORCEINLINE Vector4& operator -= (const Vector4& v) {
			this->x1 -= v.x1; this->x2 -= v.x2;
			this->x3 -= v.x3; this->x4 -= v.x4;
			return *this;
		}

		template<typename num>
		RGM_FORCEINLINE Vector4 operator * (const num val) const {
			return Vector4(this->x1 * val,
				           this->x2 * val,
				           this->x3 * val,
				           this->x4 * val);
		}

		template<typename num>
		RGM_FORCEINLINE Vector4& operator *= (const num val) {
			this->x1 *= val; this->x2 *= val;
			this->x3 *= val; this->x4 *= val;
			return *this;
		}

		template<typename num>
		friend RGM_FORCEINLINE Vector4 operator * (const num val, const Vector4& v) {
			return v * val;
		}

		RGM_FORCEINLINE Vector4 operator * (const Vector4& v) const {
			return Vector4(this->x1 * v.x1,
				           this->x2 * v.x2,
				           this->x3 * v.x3,
				           this->x4 * v.x4);
		}

		RGM_FORCEINLINE Vector4& operator *= (const Vector4& v) {
			this->x1 *= v.x1; this->x2 *= v.x2;
			this->x3 *= v.x3; this->x4 *= v.x4;
			return *this;
		} 

		// | v | of Vector4
		RGM_FORCEINLINE T length() {
			return std::sqrtf(std::pow(x1, 2) + std::pow(x2, 2) + std::pow(x3, 2) + std::pow(x4, 2));
		}

		static RGM_FORCEINLINE Vector4 Zeros() {
			return Vector4();
		}

		friend inline std::ostream& operator << (std::ostream& os, const Vector4& v) {
			os << "[ " << v.x1 << ", " << v.x2 << ", " << v.x3 << ", " << v.x4 << " ]" << std::endl;
			return os;
		}
	};
}
#endif