#include "met_aromatic.h"
#include "print.h"
#include "curl_pdb_files.h"
#include "preprocessing.h"
#include "get_aromatic_midpoints.h"


void print_data(std::vector<std::map<std::string, std::string>> data) {
    for (unsigned int i = 0; i < data.size(); ++i) {
        std::cout << data[i]["atom"] << " ";
        std::cout << data[i]["chain"] << " ";
        std::cout << data[i]["res_pos"] << " ";
        std::cout << data[i]["x_coord"] << " ";
        std::cout << data[i]["y_coord"] << " ";
        std::cout << data[i]["z_coord"] << " ";
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
    std::vector<std::map<std::string, std::string>> met_data;
    std::vector<std::map<std::string, std::string>> phe_data;
    std::vector<std::map<std::string, std::string>> tyr_data;
    std::vector<std::map<std::string, std::string>> trp_data;
    if (!preprocess_data(&raw_data, &met_data, &phe_data, &tyr_data, &trp_data, chain)) {
        print_stderr("No MET residues or no PHE/TYR/TRP residues.");
    	return EXIT_FAILURE;
    }

    get_trp_midpoints(&trp_data);

	return EXIT_SUCCESS;
}