#ifndef INCLUDE_H
#define INCLUDE_H

namespace exit_codes {
    int invalid_cutoffs_error = 3;
    int invalid_pdb_file_error = 4;
    // int missing_file_error = 5;
    int no_met_coordinates_error = 6;
    int no_aromatic_coordinates_error = 7;
    // int invalid_model_error = 8;
    int no_results_error = 9;
    // int bad_vertices_error = 10;
    // int bad_database_collection_error = 11;
    int other_error = 12;
};

#endif