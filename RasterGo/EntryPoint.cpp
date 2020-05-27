#include<RGMath.h>
#include<iostream>

using namespace rgm;
void main() {
	Matrix3<int> m = {
		{1,2,3},
		{2,3,4},
		{3,4,5}
	};

	Vector3<int> v = { 1,2,3 };
	std::cout << 3 * m;
}