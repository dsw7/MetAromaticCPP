#ifndef STRUCTS_H
#define STRUCTS_H
#include <string>

struct preprocessed {
	std::string atom;
	std::string chain;
	int residue_position;
	float x_coord;
	float y_coord;
	float z_coord;
};

struct midpoints {
	int residue_position;
	float x_coord;
	float y_coord;
	float z_coord;
};	

#endif