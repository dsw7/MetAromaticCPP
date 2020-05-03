#include "met_aromatic.h"
#include "print.h"
#include "curl_pdb_files.h"
#include "preprocessing.h"


#include <sstream>
std::vector<std::string> split(std::string str)
{
    // splits a string by whitespace
    std::vector<std::string> result;
    std::istringstream iss(str);
    for (std::string s; iss >> s; ) {
        result.push_back(s);
    }
    return result;
}


int met_aromatic_cpp(std::string code) {
	/* ---- download file ---- */
    std::string url = "https://files.rcsb.org/download/" + code + ".pdb1";
    std::string raw_data;
    if (!download_https_file(url, &raw_data)) {
        return EXIT_FAILURE;
    }

	/* ---- isolate rows of interest ---- */
    std::vector<std::string> met_data;
    std::vector<std::string> phe_data;
    std::vector<std::string> tyr_data;
    std::vector<std::string> trp_data;
    if (!preprocess_data(&raw_data, &met_data, &phe_data, &tyr_data, &trp_data, "A")) {
    	return EXIT_FAILURE;
    }

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
	
	return EXIT_SUCCESS;
}