#include "met_aromatic.h"
#include "print.h"
#include "curl_pdb_files.h"
#include "preprocessing.h"

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