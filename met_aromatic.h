#ifndef MET_AROMATIC_H
#define MET_AROMATIC_H

#include <map>
#include <string>
#include <vector>
#include <iostream>

int met_aromatic_cpp(
	std::string code,
	std::string chain,
	float cutoff_distance,
	float cutoff_angle
);

#endif