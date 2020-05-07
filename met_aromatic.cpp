#include "met_aromatic.h"
#include "print.h"
#include "curl_pdb_files.h"
#include "preprocessing.h"
#include "precompute_lone_pairs.h"
#include "precompute_aromatic_midpoints.h"
#include "distance_condition.h"


int met_aromatic_cpp(std::string code, std::string chain, float cutoff_distance) {
    // get pdb file from pdb
    std::string url = "https://files.rcsb.org/download/" + code + ".pdb1";
    std::string raw_data;
    if (!download_https_file(url, &raw_data)) {
        print_stderr("PDB entry does not exist.");
        return EXIT_FAILURE;
    }

	// isolate only relevant data from pdb file lines
    std::vector<preprocessed> met_data;
    std::vector<preprocessed> phe_data;
    std::vector<preprocessed> tyr_data;
    std::vector<preprocessed> trp_data;
    if (!preprocess_data(&raw_data, &met_data, &phe_data, &tyr_data, &trp_data, chain)) {
        print_stderr("No MET residues or no PHE/TYR/TRP residues.");
    	return EXIT_FAILURE;
    }

    // get aromatic residue midpoints
    std::vector<midpoints> phe_midpoints;
    std::vector<midpoints> tyr_midpoints;
    std::vector<midpoints> trp_midpoints;
    get_phe_midpoints(&phe_data, &phe_midpoints);
    get_tyr_midpoints(&tyr_data, &tyr_midpoints);
    get_trp_midpoints(&trp_data, &trp_midpoints);

    // get lone pairs
 	get_lone_pairs(&met_data);

    // get closely spaced met-aromatics
    //apply_distance_condition(&met_data, &phe_midpoints, cutoff_distance);
    //apply_distance_condition(&met_data, &tyr_midpoints, cutoff_distance);
    //apply_distance_condition(&met_data, &trp_midpoints, cutoff_distance);

	return EXIT_SUCCESS;
}