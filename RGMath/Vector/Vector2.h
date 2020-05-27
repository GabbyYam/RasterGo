#include"../Global.h"
#ifdef RGM_VECTOR2
#define RGM_VECTOR2

namespace rgm {
	// typedef Vector2<float> Vetor2f;
	// typedef Vector2<int>   Vetor2int;

	template <class T>
	class RGM_API Vector2 {

	public:
		union {
			struct { T x, y; }; // Coordinate basically
			struct { T u, v; }; // Texture basically
		};
		RGM_FORCEINLINE Vector2() : x(0), y(0) {};
		RGM_FORCEINLINE Vector2(T i, T j) : x(i), y(j) {};
		RGM_FORCEINLINE Vector2(T val) : x(val), y(val) {};
		RGM_FORCEINLINE Vector2(const Vector2& v) : x(v.x), y(v.y) {};
		RGM_FORCEINLINE Vector2& operator = (const Vector2& v) {
			x = v.x; y = v.y;
			return *this;
		}

		RGM_FORCEINLINE Vector2& operator == (const Vector2& v) {
			return this->x == v.x && this->y == v.y;
		}

		RGM_FORCEINLINE Vector2 operator + (const Vector2& v) {
			return Vector2(v.x + this->x, v.y + this->y);
		}

		RGM_FORCEINLINE Vector2& operator += (const Vector2& v) {
			this->x += v.x;
			this->y += v.y;
			return *this;
		}

		RGM_FORCEINLINE Vector2 operator - (const Vector2& v) {
			return Vector2(this->x - v.x, this->y - v.y);
		}

		RGM_FORCEINLINE Vector2& operator -= (const Vector2& v) {
			this->x -= v.x;
			this->y -= v.y;
			return *this;
		}

		RGM_FORCEINLINE Vector2 operator * (const Vector2& v) {
			return Vector2(this->x * v.x, this->y * v.y);
		}

		RGM_FORCEINLINE Vector2& operator *= (const Vector2& v) {
			this->x *= v.x;
			this->y *= v.y;
			return *this;
		}

		RGM_FORCEINLINE Vector2 operator * (const T& val) {
			return Vector2(this->x * val, this->y * val);
		}

		RGM_FORCEINLINE Vector2& operator *= (const T& val) {
			this->x *= val;
			this->y *= val;
			return *this;
		}

		RGM_FORCEINLINE Vector2 operator / (const Vector2& v) {
			if (v.x == 0 || v.y == 0) throw "Divide Zero!";
			return Vector2(this->x / v.x, this->y / v.y);
		}

		RGM_FORCEINLINE Vector2& operator /= (const Vector2& v) {
			if (v.x == 0 || v.y == 0) throw "Divide Zero!";
			this->x /= v.x;
			this->y /= v.y;
			return *this;
		}

		RGM_FORCEINLINE Vector2 operator / (const T& val) {
			if (val == 0) throw "Divide Zero!";
			return Vector2(this->x / val, this->y / val);
		}

		RGM_FORCEINLINE Vector2& operator /= (const T& val) {
			if (val == 0) throw "Divide Zero!";
			this->x /= val;
			this->y /= val;
			return *this;
		}

		RGM_FORCEINLINE Vector2 operator << (const Vector2& v) {
			return Vector2(this->x << v.x, this->y << v.y);
		}

		RGM_FORCEINLINE Vector2& operator <<= (const Vector2& v) {
			this->x <<= v.x;
			this->y <<= v.y;
			return *this;
		}

		RGM_FORCEINLINE Vector2 operator >> (const Vector2& v) {
			return Vector2(this->x >> v.x, this->y >> v.y);
		}

		RGM_FORCEINLINE Vector2& operator >>= (const Vector2& v) {
			this->x >>= v.x;
			this->y >>= v.y;
			return *this;
		}

		friend inline std::ostream& operator << (std::ostream& os, const Vector2& v) {
			os << "[ " << v.x << ", " << v.y << " ]" << std::endl;
			return os;
		}


		// | V | of Vector2
		RGM_FORCEINLINE T length() {
			return (T)std::sqrt((T)std::pow(this->x, 2) + (T)std::pow(this->y, 2));
		}
	};
}


#endif