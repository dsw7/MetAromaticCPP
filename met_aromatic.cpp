#include "met_aromatic.h"
#include "print.h"
#include "curl_pdb_files.h"
#include "preprocessing.h"

int met_aromatic_cpp(std::string code, std::string chain) {
	/* ---- download file ---- */
    std::string url = "https://files.rcsb.org/download/" + code + ".pdb1";
    std::string raw_data;
    if (!download_https_file(url, &raw_data)) {
        print_stderr("PDB entry does not exist.");
        return EXIT_FAILURE;
    }

	/* ---- isolate rows of interest ---- */
    std::vector<std::vector<std::string>> met_data;
    std::vector<std::vector<std::string>> phe_data;
    std::vector<std::vector<std::string>> tyr_data;
    std::vector<std::vector<std::string>> trp_data;
    if (!preprocess_data(&raw_data, &met_data, &phe_data, &tyr_data, &trp_data, chain)) {
        print_stderr("No MET residues or no PHE/TYR/TRP residues.");
    	return EXIT_FAILURE;
    }


    for (unsigned int i = 0; i < met_data.size(); ++i) {
        for (unsigned int j = 0; j < met_data[i].size(); ++j) {
            std::cout << met_data[i][j] << " ";
        }
        std::cout << std::endl;
    }

    /*
	for (std::vector<std::string>::const_iterator i = phe_data.begin(); i != phe_data.end(); ++i) {
	    std::cout << *i << std::endl;
	}

	for (std::vector<std::string>::const_iterator i = tyr_data.begin(); i != tyr_data.end(); ++i) {
	    std::cout << *i << std::endl;
	}

	for (std::vector<std::string>::const_iterator i = trp_data.begin(); i != trp_data.end(); ++i) {
	    std::cout << *i << std::endl;
	}
	*/

	return EXIT_SUCCESS;
}