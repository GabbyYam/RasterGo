#include<RGMath.h>
#include<iostream>
#include<opencv2/opencv.hpp>
#include<Eigen/Eigen>

int main() {
	Eigen::Matrix4f m = Eigen::Matrix4f::Identity();
	Eigen::Matrix4f t;
	t << 1, 2, 3, 4,
		2, 3, 4, 5,
		2, 3, 5, 6,
		1, 2, 3, 4;
	std::cout << t * m;


}