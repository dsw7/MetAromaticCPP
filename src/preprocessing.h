#ifndef PREPROCESSING_H
#define PREPROCESSING_H

#include <regex>
#include <string>
#include <vector>
#include <sstream>

const std::string SUB_PATTERN_MET = "ATOM.*(CG|CE|SD)\\s*MET\\s*";
const std::string SUB_PATTERN_PHE = "ATOM.*(CD1|CE1|CZ|CG|CD2|CE2)\\s*PHE\\s*";
const std::string SUB_PATTERN_TYR = "ATOM.*(CD1|CE1|CZ|CG|CD2|CE2)\\s*TYR\\s*";
const std::string SUB_PATTERN_TRP = "ATOM.*(CD2|CE3|CZ2|CH2|CZ3|CE2)\\s*TRP\\s*";
const unsigned int IDX_ATOM_DELIMITER = 2;
const unsigned int IDX_CHAIN = 4;
const unsigned int IDX_RESIDUE_POSITION = 5;
const unsigned int IDX_X_COORD = 6;
const unsigned int IDX_Y_COORD = 7;
const unsigned int IDX_Z_COORD = 8;

std::vector<std::string> get_relevant_data(std::string line) {
    std::vector<std::string> split_by_whitespace;
    std::istringstream iss(line);
    for (std::string s; iss >> s;) {
        split_by_whitespace.push_back(s);
    }
    std::vector<std::string> result;
    result.push_back(split_by_whitespace[IDX_ATOM_DELIMITER]);
    result.push_back(split_by_whitespace[IDX_CHAIN]);
    result.push_back(split_by_whitespace[IDX_RESIDUE_POSITION]);
    result.push_back(split_by_whitespace[IDX_X_COORD]);
    result.push_back(split_by_whitespace[IDX_Y_COORD]);
    result.push_back(split_by_whitespace[IDX_Z_COORD]);
    return result;
}

bool preprocess_data(std::string *input,
	                 std::vector<std::vector<std::string>> *met_data,
	                 std::vector<std::vector<std::string>> *phe_data,
	                 std::vector<std::vector<std::string>> *tyr_data,
	                 std::vector<std::vector<std::string>> *trp_data,
	                 std::string chain) {
	// need to break at ENDMDL in the curl stage
	std::istringstream iss(*input);
	std::regex pattern_met(SUB_PATTERN_MET + chain);
	std::regex pattern_phe(SUB_PATTERN_PHE + chain);
	std::regex pattern_tyr(SUB_PATTERN_TYR + chain);
	std::regex pattern_trp(SUB_PATTERN_TRP + chain);

	for (std::string line; getline(iss, line);) {
	    if (regex_search(line, pattern_met)) {
			met_data->push_back(get_relevant_data(line));
	    }
	    else if (regex_search(line, pattern_phe)) {
			phe_data->push_back(get_relevant_data(line));
	    }
	    else if (regex_search(line, pattern_tyr)) {
			tyr_data->push_back(get_relevant_data(line));
	    }
	    else if (regex_search(line, pattern_trp)) {
			trp_data->push_back(get_relevant_data(line));
	    }
	}

	if (met_data->size() == 0) {
		return false;
	}
	else if ((phe_data->size() + tyr_data->size() + trp_data->size()) == 0) {
		return false;
	}
	return true;
}

#endif