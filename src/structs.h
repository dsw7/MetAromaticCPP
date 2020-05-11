#ifndef STRUCTS_H
#define STRUCTS_H
#include <string>
#include <vector>

struct preprocessed {
	std::string atom;
	std::string chain;
	std::string residue;
	int residue_position;
	std::vector<float> atomic_coords;
};

struct midpoints {
	std::string chain;
	std::string residue;	
	int residue_position;
    std::vector<float> midpoint;
};

struct lone_pairs {
    std::vector<float> vector_a;
    std::vector<float> vector_g;
    std::vector<float> coord_sd;
    int residue_position;
};

struct met_aromatic_results {
	std::string aromatic_residue; 
	int aromatic_residue_position; 
	std::string methionine_residue; 
	int methionine_residue_position; 
	float norm;
	float met_theta;
	float met_phi;
};

#endif