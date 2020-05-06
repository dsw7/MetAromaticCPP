#ifndef GET_AROMATIC_MIDPOINTS_H
#define GET_AROMATIC_MIDPOINTS_H

#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include "preprocessing.h"

const std::map<std::string, std::string> MAP_ATOMS_PHE = {
    {"CG", "A"},
    {"CD2", "B"},
    {"CE2", "C"},
    {"CZ", "D"},
    {"CE1", "E"},
    {"CD1", "F"}
};

const std::map<std::string, std::string> MAP_ATOMS_TYR = {
    {"CG", "A"},
    {"CD2", "B"},
    {"CE2", "C"},
    {"CZ", "D"},
    {"CE1", "E"},
    {"CD1", "F"}
};

const std::map<std::string, std::string> MAP_ATOMS_TRP = {
    {"CD2", "A"},
    {"CE3", "B"},
    {"CZ3", "C"},
    {"CH2", "D"},
    {"CZ2", "E"},
    {"CE2", "F"}
};


struct midpoints {
	int residue_position;
	float x_coord;
	float y_coord;
	float z_coord;
};	


void get_hexagon_midpoints(std::vector<preprocessed> sorted_group, std::vector<midpoints> *results) {
	std::vector<preprocessed> frameshift = sorted_group;
	frameshift.insert(frameshift.begin(), frameshift.back());
	frameshift.pop_back();

	for (unsigned int i = 0; i < sorted_group.size(); i++) {
		midpoints mp;
		mp.residue_position = sorted_group[i].residue_position;
		mp.x_coord = 0.5 * (sorted_group[i].x_coord + frameshift[i].x_coord);
		mp.y_coord = 0.5 * (sorted_group[i].y_coord + frameshift[i].y_coord);
		mp.z_coord = 0.5 * (sorted_group[i].z_coord + frameshift[i].z_coord);
		results->push_back(mp);
	}
}

bool compare_by_alphabetic_character(const preprocessed &start, const preprocessed &end) {
    return start.atom < end.atom;
}

void get_phe_midpoints(std::vector<preprocessed> *preprocessed_data) {
    // swap atom delimiters with alphabetic characters for sorting
    for (std::vector<preprocessed>::iterator it = preprocessed_data->begin(); it != preprocessed_data->end(); ++it) {
        it->atom = MAP_ATOMS_PHE.at(it->atom);
    }

    // get unique residue positions
    std::set<int> residue_positions;
    for(unsigned int i = 0; i < preprocessed_data->size(); ++i) {
        residue_positions.insert(preprocessed_data->at(i).residue_position);
    }

    for (std::set<int>::iterator it_res = residue_positions.begin(); it_res != residue_positions.end(); ++it_res) {
        // group data according to unique residues
        std::vector<preprocessed> group;
        for (std::vector<preprocessed>::iterator it = preprocessed_data->begin(); it != preprocessed_data->end(); ++it) {
            if(it->residue_position == *it_res) {
                group.push_back(*it);
            }
        }

        // sort according to alphabetic characters
        std::sort(group.begin(), group.end(), compare_by_alphabetic_character);

        // need to get hexagon midpoints here
        get_hexagon_midpoints(group);
        /*
        for (std::vector<preprocessed>::iterator it = group.begin(); it != group.end(); ++it) {
            std::cout << it->residue_position << " " << it->atom << std::endl;
        }
        std::cout << std::endl;
        */
    }
}

#endif