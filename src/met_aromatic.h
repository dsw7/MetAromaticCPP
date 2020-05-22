#ifndef MET_AROMATIC_H
#define MET_AROMATIC_H

#include <string>
#include <vector>
#include <iostream>
#include "structs.h"

#ifndef CXX_CHAIN
    #define CXX_CHAIN "A"
#endif

#ifndef CXX_CUTOFF_ANGLE
    #define CXX_CUTOFF_ANGLE 109.5
#endif

#ifndef CXX_CUTOFF_DISTANCE
    #define CXX_CUTOFF_DISTANCE 6.0
#endif

#ifndef PRINT_CSV
	#define PRINT_CSV 0
#endif

results_all_interactions met_aromatic_cpp(
	std::string code,
	std::string chain,
	float cutoff_distance,
	float cutoff_angle
);

#endif