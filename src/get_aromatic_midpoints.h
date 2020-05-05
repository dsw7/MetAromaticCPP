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


/*
const std::map<std::string, std::string> MAP_ATOMS_TRP;
MAP_ATOMS_TRP["CD2"] = std::string("A");
MAP_ATOMS_TRP["CE3"] = std::string("B");
MAP_ATOMS_TRP["CZ3"] = std::string("C");
MAP_ATOMS_TRP["CH2"] = std::string("D");
MAP_ATOMS_TRP["CZ2"] = std::string("E");
MAP_ATOMS_TRP["CE2"] = std::string("F");
}
*/

bool compare_by_special_key(const preprocessed &start, const preprocessed &end) {
    return start.atom < end.atom;
}

void get_trp_midpoints(std::vector<preprocessed> *trp_data) {
    // swap atom delimiters with sortable alphabetic characters
    for (std::vector<preprocessed>::iterator it = trp_data->begin(); it != trp_data->end(); ++it) {
        it->atom = MAP_ATOMS_PHE.at(it->atom);
    }

    // get unique residue positions
    std::set<int> residue_positions;
    for(unsigned int i = 0; i < trp_data->size(); ++i) {
        residue_positions.insert(trp_data->at(i).residue_position);
    }

    for (std::set<int>::iterator it_res = residue_positions.begin(); it_res != residue_positions.end(); ++it_res) {
        std::cout << *it_res << std::endl;

        for (std::vector<preprocessed>::iterator it = trp_data->begin(); it != trp_data->end(); ++it) {
            if(it->residue_position == *it_res) {
                std::cout << it->residue_position << " " << it->atom << std::endl;
            }
        }

        std::cout << std::endl;
    }

}

#endif