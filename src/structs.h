#ifndef STRUCTS_H
#define STRUCTS_H
#include <string>

struct preprocessed {
	std::string atom;
	std::string chain;
	std::string residue;
	int residue_position;
	float x_coord;
	float y_coord;
	float z_coord;
};

struct midpoints {
	std::string chain; // remove this?
	std::string residue;	
	int residue_position;
	float x_coord;
	float y_coord;
	float z_coord;
};

struct lone_pairs {
    std::vector<float> vector_a;
    std::vector<float> vector_g;
    std::vector<float> coord_sd;
    int residue_position;
};

#endif