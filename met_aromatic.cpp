#include "met_aromatic.h"
#include "print.h"
#include "curl_pdb_files.h"

int met_aromatic_cpp(std::string code) {
	int retval = 0;

    std::string url = "https://files.rcsb.org/download/" + code + ".pdb1";
    std::string raw_data;

    if (download_https_file(url, &raw_data)) {
        std::cout << raw_data << std::endl;
    }
    else {
        retval = 1;
    }

	return retval;
}