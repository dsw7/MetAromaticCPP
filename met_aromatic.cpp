#include "met_aromatic.h"
#include "print.h"
#include "curl_pdb_files.h"
#include "preprocessing.h"


void print_data(std::vector<std::vector<std::string>> data) {
    for (unsigned int i = 0; i < data.size(); ++i) {
        for (unsigned int j = 0; j < data[i].size(); ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }    
}


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

    print_data(met_data);
    print_data(phe_data);
    print_data(tyr_data);
    print_data(trp_data);

	return EXIT_SUCCESS;
}