#ifndef MET_AROMATIC_H
#define MET_AROMATIC_H

#include <string>
#include <vector>
#include <iostream>
#include "structs.h"

results_all_interactions met_aromatic_cpp(
	std::string code,
	std::string chain,
	float cutoff_distance,
	float cutoff_angle
);

#endif