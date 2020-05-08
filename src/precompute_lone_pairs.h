#ifndef PRECOMPUTE_LONE_PAIRS_H
#define PRECOMPUTE_LONE_PAIRS_H
#include <vector>
#include <iostream>
#include <set>
#include "structs.h"
#include "linalg.h"

void debug_preprocessed(std::vector<preprocessed>::iterator inst) {
    std::cout << inst->residue << " ";
    std::cout << inst->atom << " ";
    std::cout << inst->chain << " ";
    std::cout << inst->residue_position << " ";
    std::cout << inst->x_coord << " ";
    std::cout << inst->y_coord << " ";
    std::cout << inst->z_coord << " ";
    std::cout << std::endl;
}

void get_lone_pairs_from_group(std::vector<preprocessed> *group) {
    std::vector<float> coord_cg, coord_sd, coord_ce;
    for (std::vector<preprocessed>::iterator it = group->begin(); it != group->end(); ++it) {
        if (it->atom == "CG") {
            coord_ce = {it->x_coord, it->y_coord, it->z_coord};
        }
        else if (it->atom == "SD") {
            coord_sd = {it->x_coord, it->y_coord, it->z_coord};
        }
        else if (it->atom == "CE") {
            coord_cg = {it->x_coord, it->y_coord, it->z_coord};
        }
    }

    std::vector<float> vector_a, vector_g;
    subtract_vector(&coord_ce, &coord_sd, &vector_a);
    subtract_vector(&coord_cg, &coord_sd, &vector_g);

    //debug_preprocessed(it);
}

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

        get_lone_pairs_from_group(&group);

        /*
        for(unsigned int i = 0; i < group.size(); ++i) {
        	std::cout << group[i].residue_position << std::endl;
        }
        */
        std::cout << std::endl;
    }
}

#endif