#include "met_aromatic.h"
#include "print.h"
#include "curl_pdb_files.h"


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


int met_aromatic_cpp(std::string code) {
	/* download file */
    std::string url = "https://files.rcsb.org/download/" + code + ".pdb1";
    std::string raw_data;
    if (!download_https_file(url, &raw_data)) {
        return 1;
    }

    std::vector<std::string> met_data;
    std::vector<std::string> phe_data;
    std::vector<std::string> tyr_data;
    std::vector<std::string> trp_data;
    preprocess_data(&raw_data, &met_data, &phe_data, &tyr_data, &trp_data, "A");


	for (std::vector<std::string>::const_iterator i = met_data.begin(); i != met_data.end(); ++i) {
	    std::cout << *i << std::endl;
	}

	for (std::vector<std::string>::const_iterator i = phe_data.begin(); i != phe_data.end(); ++i) {
	    std::cout << *i << std::endl;
	}

	for (std::vector<std::string>::const_iterator i = tyr_data.begin(); i != tyr_data.end(); ++i) {
	    std::cout << *i << std::endl;
	}

	for (std::vector<std::string>::const_iterator i = trp_data.begin(); i != trp_data.end(); ++i) {
	    std::cout << *i << std::endl;
	}

	return 0;
}