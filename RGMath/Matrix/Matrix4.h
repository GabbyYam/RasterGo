#pragma once
#include"../Global.h"
#include"../Vector/Vector4.h"
#ifdef RGM_MATRIX4
#define RGM_MATRIX4

namespace rgm {
	template<class T>
	class RGM_API Matrix4 {
	private:
		struct {
			Vector4<T> r1, r2, r3, r4;
		};

	public:
		RGM_FORCEINLINE Matrix4()
			: r1(Vector4<T>()), r2(Vector4<T>()), r3(Vector4<T>()), r4(Vector4<T>()) {};


		RGM_FORCEINLINE Matrix4(const Vector4<T>& v )
			: r1(v), r2(v), r3(v), r4(v) {};


		RGM_FORCEINLINE Matrix4(const Vector4<T>& v1, const Vector4<T>& v2, 
			const Vector4<T>& v3, const Vector4<T>& v4)
			: r1(v1), r2(v2), r3(v3), r4(v4) {};

		RGM_FORCEINLINE Matrix4(const Matrix4& m)
			: r1(m.r1), r2(m.r2), r3(m.r3), r4(m.r4) {};

		RGM_FORCEINLINE Matrix4& operator = (const Matrix4& m) {
			this->r1 = m.r1; this->r2 = m.r2;
			this->r3 = m.r3; this->r4 = m.r4;
			return *this;
		}

		RGM_FORCEINLINE bool operator == (const Matrix4& m) const {
			return this->r1 == m.r1 && this->r2 == m.r2 
				&& this->r3 == m.r3 && this->r4 == m.r4;
		}

		RGM_FORCEINLINE Matrix4 operator + (const Matrix4& m) const {
			return Matrix4(
				this->r1 + m.r1, this->r2 + m.r2,
				this->r3 + m.r3, this->r4 + m.r4
			);
		}

		RGM_FORCEINLINE Matrix4& operator += (const Matrix4& m) {
			this->r1 += m.r1; this->r2 += m.r2;
			this->r3 += m.r3; this->r4 += m.r4;
			return* this;
		}

		RGM_FORCEINLINE Matrix4 operator - (const Matrix4& m) const {
			return Matrix4(
				this->r1 - m.r1, this->r2 - m.r2,
				this->r3 - m.r3, this->r4 - m.r4
			);
		}

		RGM_FORCEINLINE Matrix4& operator -= (const Matrix4& m) {
			this->r1 -= m.r1; this->r2 -= m.r2;
			this->r3 -= m.r3; this->r4 -= m.r4;
			return* this;
		}

		// Number multiplying
		template<typename num>
		RGM_FORCEINLINE Matrix4 operator * (const num val) const {
			return Matrix4(
				this->r1 * val, this->r2 * val,
				this->r3 * val, this->r4 * val
			);
		}

		template<typename num>
		friend RGM_FORCEINLINE Matrix4 operator * (const num val, const Matrix4& m) {
			return m * val;
		}

		// Matrix multiplying
		RGM_FORCEINLINE Matrix4 operator * (const Matrix4& m) const {
			// TODO: column vector * row vector
		}

	};
}

#endif
