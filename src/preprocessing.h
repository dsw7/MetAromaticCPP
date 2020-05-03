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

void preprocess_data(std::string *input,
	                 std::vector<std::string> *met_data,
	                 std::vector<std::string> *phe_data,
	                 std::vector<std::string> *tyr_data,
	                 std::vector<std::string> *trp_data,
	                 std::string chain) {
	// need to break at ENDMDL in the curl stage
	std::istringstream iss(*input);
	std::regex pattern_met(SUB_PATTERN_MET + chain);
	std::regex pattern_phe(SUB_PATTERN_PHE + chain);
	std::regex pattern_tyr(SUB_PATTERN_TYR + chain);
	std::regex pattern_trp(SUB_PATTERN_TRP + chain);

	for (std::string line; getline(iss, line);) {
	    if (regex_search(line, pattern_met)) {
			met_data->push_back(line);
	    }
	    else if (regex_search(line, pattern_phe)) {
			phe_data->push_back(line);
	    }
	    else if (regex_search(line, pattern_tyr)) {
			tyr_data->push_back(line);
	    }
	    else if (regex_search(line, pattern_trp)) {
			trp_data->push_back(line);
	    }
	}
}

#endif