#ifndef GET_AROMATIC_MIDPOINTS_H
#define GET_AROMATIC_MIDPOINTS_H

#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include "preprocessing.h"

bool compare_by_residue_position(const preprocessed &start, const preprocessed &end) {
    return start.residue_position < end.residue_position;
}

void get_trp_midpoints(std::vector<preprocessed> *trp_data) {
	std::sort(trp_data->begin(), trp_data->end(), compare_by_residue_position);

	for(unsigned int i = 0; i < trp_data->size(); ++i) {
		std::cout << trp_data->at(i).residue_position << " " << trp_data->at(i).atom << std::endl;
	}

	// need to figure out next steps

	/*
    std::set<std::string> res;
    for (std::vector<std::map<std::string, std::string>>::iterator it = trp_data->begin(); it != trp_data->end(); ++it) {
        res.insert(it->at("res_pos"));
    }

    for (std::set<std::string>::iterator it = res.begin(); it != res.end(); ++it) {
        std::cout << *it << std::endl;
    }
    */
}

#endif