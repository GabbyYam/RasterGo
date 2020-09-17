#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

struct Coordinate {
	int x, y, z;
	int operator [] (int idx) {
		if (idx < 0 || idx > 2) std::cout << "error!" << std::endl;
		return idx == 0 ? x : idx == 1 ? y : z;
	}
	friend int operator [] (int idx) {

	}
};

class Model
{
private:
	std::vector<Coordinate> vectices;
	std::vector<std::vector<int>> faces;
public:
	Model(std::string filename);
	~Model();
	int nvert();
	int nfaces();
	Coordinate vert(int idx);
	std::vector<int> face(int idx);

};

