#include"../Global.h"
#ifdef RGM_MATRIX
#define RGM_MATRIX
#include<vector>
#include"../Global.h"
namespace rgm {
	template<class T>
	class Matrix {
	public:
		RGM_FORCEINLINE Matrix(int row, int col, T val) :
			matrix(std::vector<std::vector<T>>(row, std::vector<T>(col, val))), r(row), c(col) {};

		RGM_FORCEINLINE Matrix(int row, int col) :
			matrix(std::vector<std::vector<T>>(row, std::vector<T>(col))), r(row), c(col) {};

		RGM_FORCEINLINE Matrix(const Matrix& m) {
			this->matrix = m.matrix;
			return *this;
		}

		RGM_FORCEINLINE Matrix& operator = (const Matrix& m) {
			this->matrix = m.matrix;
			return *this;
		}

		RGM_FORCEINLINE bool operator == (const Matrix& m) {
			if (m.r != this->m.r || m.c != this->c) return false;
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (m.matrix[i][j] != this->matrix[i][j])
						return false;
				}
			}
			return true;
		}

		RGM_FORCEINLINE Matrix operator + (const Matrix& m) const {
			if (m.r != this->m.r || m.c != this->c) throw "Illegal shape of matrix using!";
			Matrix nmatrix = Matrix(m.r, m.c);
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					nmatrix.matrix[i][j] = this->matrix[i][j] + m.matrix[i][j];
				}
			}
			return nmatrix;
		}

		RGM_FORCEINLINE std::ostream& operator << (std::ostream& os, const Matrix& m) {
			
		}

		RGM_FORCEINLINE ~Matrix() { delete this; }

	private:
		const std::vector<std::vector<T>> matrix;
		const int r, c;
	};
}
#endif

