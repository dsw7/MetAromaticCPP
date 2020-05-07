#ifndef PRECOMPUTE_LONE_PAIRS_H
#define PRECOMPUTE_LONE_PAIRS_H
#include <vector>
#include <iostream>
#include <set>
#include "structs.h"

void get_lone_pairs(std::vector<preprocessed> *met_data) {
    // get unique residue positions
    std::set<int> residue_positions;
	for (std::vector<preprocessed>::iterator it = met_data->begin(); it != met_data->end(); ++it) {
	 	residue_positions.insert(it->residue_position);
    }

    for (std::set<int>::iterator it_res = residue_positions.begin(); it_res != residue_positions.end(); ++it_res) {
        // group data according to unique residues
        std::vector<preprocessed> group;
        for (std::vector<preprocessed>::iterator it = met_data->begin(); it != met_data->end(); ++it) {
            if(it->residue_position == *it_res) {
                group.push_back(*it);
            }
        }

        for(unsigned int i = 0; i < group.size(); ++i) {
        	std::cout << group[i].residue_position << std::endl;
        }
        std::cout << std::endl;
    }
}

#endif