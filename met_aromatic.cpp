#include "met_aromatic.h"
#include "print.h"
#include "curl_pdb_files.h"
#include "preprocessing.h"


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


#include <set>
void get_midpoints(std::vector<std::map<std::string, std::string>> *data) {
    std::set<std::string> res;
    for (std::vector<std::map<std::string, std::string>>::iterator it = data->begin(); it != data->end(); ++it) {
        res.insert(it->at("res_pos"));
    }

    for (std::set<std::string>::iterator it = res.begin(); it != res.end(); ++it) {
        std::cout << *it << std::endl;
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

    //print_data(met_data);
    //print_data(phe_data);
    //print_data(tyr_data);
    //print_data(trp_data);
    get_midpoints(&trp_data);


	return EXIT_SUCCESS;
}