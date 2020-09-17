#include"../Global.h"
#include"../Vector/Vector3.h"
#ifdef RGM_MATRIX3
#define RGM_MATRIX3

namespace rgm {
	template <class T>
	class RGM_API Matrix3
	{
	private:
		struct {
			Vector3<T> r1, r2, r3;
		};
		
	public:
		RGM_FORCEINLINE Matrix3()
			: r1(Vector3<T>()), r2(Vector3<T>()), r3(Vector3<T>()) {};

		RGM_FORCEINLINE Matrix3(const Vector3<T>& v)
			: r1(v), r2(v), r3(v) {};

		RGM_FORCEINLINE Matrix3(const Vector3<T>& v1, const Vector3<T>& v2, const Vector3<T>& v3)
			: r1(v1), r2(v2), r3(v3) {};

		RGM_FORCEINLINE Matrix3(const Matrix3& m)
			: r1(m.r1), r2(m.r2), r3(m.r3) {};

		RGM_FORCEINLINE Matrix3& operator = (const Matrix3& m) {
			this->r1 = m.r1; this->r2 = m.r2; this->r3 = m.r3;
			return *this;
		}

		RGM_FORCEINLINE bool operator == (const Matrix3& m) {
			return this->r1 == m.r1 && this->r2 == m.r2 && this->r3 == m.r3;
		}

		RGM_FORCEINLINE Matrix3 operator + (const Matrix3& m) {
			return Matrix3(this->r1 + m.r1, this->r2 + m.r2, this->r2 + m.r3);
		}

		RGM_FORCEINLINE Matrix3& operator += (const Matrix3& m) {
			this->r1 += m.r1;
			this->r2 += m.r2;
			this->r3 += m.r3;
			return *this;
		}

		RGM_FORCEINLINE Matrix3 operator - (const Matrix3& m) {
			return Matrix3(this->r1 - m.r1, this->r2 - m.r2, this->r2 - m.r3);
		}

		RGM_FORCEINLINE Matrix3& operator -= (const Matrix3& m) {
			this->r1 -= m.r1;
			this->r2 -= m.r2;
			this->r3 -= m.r3;
			return *this;
		}

		template <typename num>
		RGM_FORCEINLINE Matrix3 operator * (const num val) {
			return Matrix3(this->r1 * val, this->r2 * val, this->r3 * val);
		}

		template <typename num>
		friend RGM_FORCEINLINE Matrix3 operator * (num val, Matrix3& m) {
			return Matrix3(m.r1 * val, m.r2 * val, m.r3 * val);
		}

		RGM_FORCEINLINE Matrix3 operator * (const Matrix3& m) {
			return Matrix3(
				{
					r1.x1 * m.r1.x1 + r1.x2 * m.r2.x1 + r1.x3 * m.r3.x1,
					r1.x1 * m.r1.x2 + r1.x2 * m.r2.x2 + r1.x3 * m.r3.x2,
					r1.x1 * m.r1.x3 + r1.x2 * m.r2.x3 + r1.x3 * m.r3.x3
				},

				{
					r2.x1 * m.r2.x1 + r2.x2 * m.r2.x1 + r2.x3 * m.r3.x1,
					r2.x1 * m.r1.x2 + r2.x2 * m.r2.x2 + r2.x3 * m.r3.x2,
					r2.x1 * m.r1.x3 + r2.x2 * m.r2.x3 + r2.x3 * m.r3.x3
				},

				{
					r3.x1 * m.r1.x1 + r3.x2 * m.r2.x1 + r3.x3 * m.r3.x1,
					r3.x1 * m.r1.x2 + r3.x2 * m.r2.x2 + r3.x3 * m.r3.x2,
					r3.x1 * m.r1.x3 + r3.x2 * m.r2.x3 + r3.x3 * m.r3.x3
				}
				);
		}

		RGM_FORCEINLINE Matrix3& operator *= (const Matrix3& m) {
			*this = *this * m;
			return *this;
		}

		RGM_FORCEINLINE T det() {
			return r1.x1 * r2.x2 * r3.x3 +
				r1.x2 * r2.x3 * r3.x1 +
				r2.x1 * r3.x2 * r1.x3 -
				r1.x3 * r2.x2 * r3.x1 -
				r1.x2 * r2.x1 * r3.x3 -
				r1.x1 * r2.x3 * r3.x2;
		}

		RGM_FORCEINLINE Matrix3 T() {
			return Matrix3(
				{ r1.x1, r2.x1, r3.x1 },
				{ r1.x2, r2.x2, r3.x2 },
				{ r1.x3, r2.x3, r3.x3 }
			);
		}

		RGM_FORCEINLINE auto operator [] (int x) {
			if (x < 1 || x > 3) throw "Illegal parameter passed!";
			return x == 1 ? this->r1 : x == 2 ? this->r2 : this->r3;
		}

		static RGM_FORCEINLINE Matrix3 Zeros() {
			return Matrix3({ 0,0,0 });
		}

		static RGM_FORCEINLINE Matrix3 Identity() {
			return Matrix3(
				{ 1,0,0 },
				{ 0,1,0 },
				{ 0,0,1 }
			);
		}

		RGM_FORCEINLINE Matrix3 pow(int val) {
			Matrix3 t = *this, res = t;
			for (int i = 0; i < val; ++i)
				res *= t;
			return res;
		}

		friend inline std::ostream& operator << (std::ostream& os, const Matrix3& m) {
			os << m.r1 << m.r2 << m.r3;
			return os;
		}

	};

}

#endif