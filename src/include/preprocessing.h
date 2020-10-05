#ifndef PREPROCESSING_H
#define PREPROCESSING_H
#include <regex>
#include <string>
#include <vector>
#include <sstream>
#include "structs.h"


const std::string SUB_PATTERN_MET = "ATOM.*(CG|CE|SD)\\s+MET\\s+";
const std::string SUB_PATTERN_PHE = "ATOM.*(CD1|CE1|CZ|CG|CD2|CE2)\\s+PHE\\s+";
const std::string SUB_PATTERN_TYR = "ATOM.*(CD1|CE1|CZ|CG|CD2|CE2)\\s+TYR\\s+";
const std::string SUB_PATTERN_TRP = "ATOM.*(CD2|CE3|CZ2|CH2|CZ3|CE2)\\s+TRP\\s+";
const std::string SUB_PATTERN_MDL = "ENDMDL";
const unsigned int IDX_ATOM_DELIMITER = 2;
const unsigned int IDX_RESIDUE = 3;
const unsigned int IDX_CHAIN = 4;
const unsigned int IDX_RESIDUE_POSITION = 5;
const unsigned int IDX_X_COORD = 6;
const unsigned int IDX_Y_COORD = 7;
const unsigned int IDX_Z_COORD = 8;


preprocessed extract_relevant_data(std::string *line) {
    std::vector<std::string> split_by_whitespace;
    std::istringstream iss(*line);
    for (std::string s; iss >> s;) {
        split_by_whitespace.push_back(s);
    }
    preprocessed map_relevant_data;
	map_relevant_data.atom = split_by_whitespace[IDX_ATOM_DELIMITER];
	map_relevant_data.residue = split_by_whitespace[IDX_RESIDUE];
	map_relevant_data.chain = split_by_whitespace[IDX_CHAIN];
	map_relevant_data.residue_position = std::stoi(split_by_whitespace[IDX_RESIDUE_POSITION]);
	map_relevant_data.atomic_coords = {
		std::stof(split_by_whitespace[IDX_X_COORD]),
		std::stof(split_by_whitespace[IDX_Y_COORD]),
		std::stof(split_by_whitespace[IDX_Z_COORD])
	};
    return map_relevant_data;
}


void preprocess_data(std::string *input,
	                 std::vector<preprocessed> *met_data,
	                 std::vector<preprocessed> *phe_data,
	                 std::vector<preprocessed> *tyr_data,
	                 std::vector<preprocessed> *trp_data,
	                 std::string chain) {
	std::istringstream iss(*input);
	std::regex pattern_met(SUB_PATTERN_MET + chain + "\\s");
	std::regex pattern_phe(SUB_PATTERN_PHE + chain + "\\s");
	std::regex pattern_tyr(SUB_PATTERN_TYR + chain + "\\s");
	std::regex pattern_trp(SUB_PATTERN_TRP + chain + "\\s");
	std::regex pattern_mdl(SUB_PATTERN_MDL);

	for (std::string line; getline(iss, line);) {
	    if (regex_search(line, pattern_mdl)) {
	    	break;
	    }
	    else if (regex_search(line, pattern_met)) {
			met_data->push_back(extract_relevant_data(&line));
	    }
	    else if (regex_search(line, pattern_phe)) {
			phe_data->push_back(extract_relevant_data(&line));
	    }
	    else if (regex_search(line, pattern_tyr)) {
			tyr_data->push_back(extract_relevant_data(&line));
	    }
	    else if (regex_search(line, pattern_trp)) {
			trp_data->push_back(extract_relevant_data(&line));
	    }
	}
}

#endif