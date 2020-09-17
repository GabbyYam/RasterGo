#include "Model.h"

Model::Model(std::string filename) : vectices(), faces()
{
	std::ifstream in;
	in.open(filename.c_str(), std::ifstream::in);
	if (in.fail()) return;
	std::string line;
	while (!in.eof()) {
		std::getline(in, line);
		std::stringstream ss(line.c_str());
		char trash;
		if (!line.compare(0, 2, "v ")) {
			ss >> trash;
			Coordinate pos;
			std::string s;
			for (int i = 0; i < 3; ++i) {
				ss >> s;
				pos[i] = stoi(s);
			}
		}
	}
}
