#include "met_aromatic.h"
#include "curl_pdb_files.h"
#include "preprocessing.h"
#include "precompute_lone_pairs.h"
#include "precompute_aromatic_midpoints.h"
#include "distance_angular.h"
#include "debug.h"
#include "exit_codes.h"
#include "print_results.h"

results_all_interactions met_aromatic_cpp(std::string code, std::string chain, float cutoff_distance, float cutoff_angle) {
	results_all_interactions results;
	results._id = code;

    if ( !(cutoff_distance > 0.00) ) {
        results.exit_code = exit_codes::invalid_cutoffs_error;
        results.exit_status = "Invalid cutoff distance";
        return results;
    }

    if ((cutoff_angle < 0.00) || (cutoff_angle > 360.00)) {
        results.exit_code = exit_codes::invalid_cutoffs_error;
        results.exit_status = "Invalid cutoff angle";
        return results;
    }

    std::string url = "https://files.rcsb.org/download/" + code + ".pdb1";
    std::string raw_data;
    if (!download_https_file(url, &raw_data)) {
    	results.exit_code = exit_codes::invalid_pdb_file_error;
    	results.exit_status = "Invalid PDB file";
    	return results;
    }

    std::vector<preprocessed> met_data;
    std::vector<preprocessed> phe_data;
    std::vector<preprocessed> tyr_data;
    std::vector<preprocessed> trp_data;
    preprocess_data(&raw_data, &met_data, &phe_data, &tyr_data, &trp_data, chain);

    if (met_data.size() == 0) {
        results.exit_code = exit_codes::no_met_coordinates_error;
        results.exit_status = "No MET residues";
        return results;
    }
    else if ((phe_data.size() + tyr_data.size() + trp_data.size()) == 0) {
        results.exit_code = exit_codes::no_aromatic_coordinates_error;
        results.exit_status = "No PHE/TYR/TRP residues";
        return results;
    }

#if DEBUG_PHE == 1
    debug_preprocessed(&phe_data);
#endif
#if DEBUG_TYR == 1
    debug_preprocessed(&tyr_data);
#endif
#if DEBUG_TRP == 1
    debug_preprocessed(&trp_data);
#endif
#if DEBUG_MET == 1
    debug_preprocessed(&met_data);
#endif

    std::vector<midpoints> phe_midpoints;
    std::vector<midpoints> tyr_midpoints;
    std::vector<midpoints> trp_midpoints;
    get_phe_midpoints(&phe_data, &phe_midpoints);
    get_tyr_midpoints(&tyr_data, &tyr_midpoints);
    get_trp_midpoints(&trp_data, &trp_midpoints);

#if DEBUG_PHE == 1
    debug_midpoints(&phe_midpoints);
#endif
#if DEBUG_TYR == 1
    debug_midpoints(&tyr_midpoints);
#endif
#if DEBUG_TRP == 1
    debug_midpoints(&trp_midpoints);
#endif

    std::vector<lone_pairs> met_lone_pairs;
    if (!get_lone_pairs(&met_data, &met_lone_pairs)) {
        results.exit_code = exit_codes::corrupted_met_data_error;
        results.exit_status = "Corrupted methionine data";
        return results; 
    };

#if DEBUG_MET == 1
    debug_lone_pairs(&met_lone_pairs);
#endif

    std::vector<results_single_interaction> all_interactions;
    apply_distance_angular_condition(&met_lone_pairs, &phe_midpoints, cutoff_distance, cutoff_angle, &all_interactions);
    apply_distance_angular_condition(&met_lone_pairs, &tyr_midpoints, cutoff_distance, cutoff_angle, &all_interactions);
    apply_distance_angular_condition(&met_lone_pairs, &trp_midpoints, cutoff_distance, cutoff_angle, &all_interactions);

    if (all_interactions.size() < 1) {
        results.exit_code = exit_codes::no_results_error;
    	results.exit_status = "No interactions";
    	return results;
    }

    results.exit_code = EXIT_SUCCESS;
    results.exit_status = "Success";
    results.results = all_interactions;
	return results;
}

// ***********************************************
// functions not used in Cython code - only binary
// ***********************************************

int run_single_query(std::string code) {
    results_all_interactions results = met_aromatic_cpp(
        code,
        CXX_CHAIN,
        CXX_CUTOFF_DISTANCE,
        CXX_CUTOFF_ANGLE
    );

#if PRINT_CSV == 1
    print_csv_results(&results.results);
#else
    print_pretty_results(&results.results);
#endif
    return results.exit_code;
}

int run_batch_query(std::string path_to_batch_file) {
    // experimental feature
    std::cout << path_to_batch_file << std::endl;
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: $ ./met_aromatic <options>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string query_type(argv[1]);

    if (query_type.compare("ai") == 0) {
        return run_single_query(argv[2]);
    }
    else if (query_type.compare("batch") == 0) {
        return run_batch_query(argv[2]);
    }
    else {
        std::cerr << "Invalid query type. Usage: $ ./met_aromatic <ai|batch> <...>" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}