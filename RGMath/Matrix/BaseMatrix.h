#pragma once
#include"../Global.h"
#ifdef RGM_MATRIX
#define RGM_MATRIX
namespace rgm {
	template<class T>
	class RGM_API BaseMatrix
	{
	public:
		std::shared_ptr<T*> matrix;
		size_t rows, cols;
	public:
		RGM_FORCEINLINE BaseMatrix(size_t row, size_t col) {
			matrix = std::shared_ptr<T*>(new T*[row]);
			for (int i = 0; i < rows; ++i) {
				matrix.get()[i] = new T[col];
				memset(matrix.get()[i], 0, col * sizeof(T));
			}
			this->rows = row, this->cols = col;
		}

		virtual RGM_FORCEINLINE ~BaseMatrix() {}

		RGM_FORCEINLINE BaseMatrix(size_t row, size_t col, T val) {
			BaseMatrix(row, col);
		}

		RGM_FORCEINLINE T* operator [](int x) {
			return matrix.get()[x];
		}
	};
}
#endif
