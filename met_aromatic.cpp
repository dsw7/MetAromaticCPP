#include "met_aromatic.h"
#include "print.h"
#include "curl_pdb_files.h"
#include "preprocessing.h"
#include "precompute_lone_pairs.h"
#include "precompute_aromatic_midpoints.h"
#include "distance_angular.h"
#include "debug.h"


int met_aromatic_cpp(std::string code, std::string chain, float cutoff_distance, float cutoff_angle) {
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

#if DEBUG_PHE == 1
    debug_preprocessed(&phe_data);
#elif DEBUG_TYR == 1
    debug_preprocessed(&tyr_data);
#elif DEBUG_TRP == 1
    debug_preprocessed(&trp_data);
#elif DEBUG_MET == 1
    debug_preprocessed(&met_data);
#endif

    // get aromatic residue midpoints
    std::vector<midpoints> phe_midpoints;
    std::vector<midpoints> tyr_midpoints;
    std::vector<midpoints> trp_midpoints;
    get_phe_midpoints(&phe_data, &phe_midpoints);
    get_tyr_midpoints(&tyr_data, &tyr_midpoints);
    get_trp_midpoints(&trp_data, &trp_midpoints);

#if DEBUG_PHE == 1
    debug_midpoints(&phe_midpoints);
#elif DEBUG_TYR == 1
    debug_midpoints(&tyr_midpoints);
#elif DEBUG_TRP == 1
    debug_midpoints(&trp_midpoints);
#endif

    // get lone pairs
    std::vector<lone_pairs> met_lone_pairs;
 	get_lone_pairs(&met_data, &met_lone_pairs);

#if DEBUG_MET == 1
    debug_lone_pairs(&met_lone_pairs);
#endif

    // apply met aromatic conditions here
    // angles do not match Python met-aromatic
    apply_distance_angular_condition(&met_lone_pairs, &phe_midpoints, cutoff_distance, cutoff_angle);
    apply_distance_angular_condition(&met_lone_pairs, &tyr_midpoints, cutoff_distance, cutoff_angle);
    apply_distance_angular_condition(&met_lone_pairs, &trp_midpoints, cutoff_distance, cutoff_angle);

	return EXIT_SUCCESS;
}