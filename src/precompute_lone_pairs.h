#ifndef PRECOMPUTE_LONE_PAIRS_H
#define PRECOMPUTE_LONE_PAIRS_H
#include <vector>
#include <iostream>
#include <set>
#include "structs.h"
#include "linalg.h"

const float SCAL_ROOT_2 = pow(2, 0.5);

class CrossProductMethod {
private:
    std::vector<float> vec_u;
    std::vector<float> vec_v;
    std::vector<float> vec_anti_parallel;

public:
    CrossProductMethod(std::vector<float> *coord_cg, std::vector<float> *coord_sd, std::vector<float> *coord_ce) {
        linalg::vector_subtract(coord_cg, coord_sd, &vec_u);
        linalg::vector_subtract(coord_ce, coord_sd, &vec_v);

        std::vector<float> unit_vec_u;
        std::vector<float> unit_vec_v;
        linalg::vector_unit(&vec_u, &unit_vec_u);
        linalg::vector_unit(&vec_v, &unit_vec_v);

        std::vector<float> unit_vec_sums;
        linalg::vector_add(&unit_vec_u, &unit_vec_v, &unit_vec_sums);

        std::vector<float> unit_vec_sums_scaled;
        linalg::vector_scale(&unit_vec_sums, -0.5, &unit_vec_sums_scaled);

        linalg::vector_unit(&unit_vec_sums_scaled, &vec_anti_parallel);
    }

    ~CrossProductMethod() {}

    void get_vector_a(std::vector<float> *vector_a) {
        std::vector<float> vec_cross;
        linalg::vector_cross_product(&vec_u, &vec_v, &vec_cross);

        std::vector<float> unit_vec_cross;
        linalg::vector_unit(&vec_cross, &unit_vec_cross);

        std::vector<float> scaled_unit_vec_cross;
        linalg::vector_scale(&unit_vec_cross, SCAL_ROOT_2, &scaled_unit_vec_cross);

        linalg::vector_add(&vec_anti_parallel, &scaled_unit_vec_cross, vector_a);
    }

    void get_vector_g(std::vector<float> *vector_a) {
        std::vector<float> vec_cross;
        linalg::vector_cross_product(&vec_v, &vec_u, &vec_cross);

        std::vector<float> unit_vec_cross;
        linalg::vector_unit(&vec_cross, &unit_vec_cross);

        std::vector<float> scaled_unit_vec_cross;
        linalg::vector_scale(&unit_vec_cross, SCAL_ROOT_2, &scaled_unit_vec_cross);

        linalg::vector_add(&vec_anti_parallel, &scaled_unit_vec_cross, vector_a);
    }        
};

void get_lone_pairs_from_group(std::vector<preprocessed> *group) {
    std::vector<float> coord_cg, coord_sd, coord_ce;
    for (std::vector<preprocessed>::iterator it = group->begin(); it != group->end(); ++it) {
        if (it->atom == "CG") {
            coord_ce = {it->x_coord, it->y_coord, it->z_coord};
        }
        else if (it->atom == "SD") {
            coord_sd = {it->x_coord, it->y_coord, it->z_coord};
        }
        else if (it->atom == "CE") {
            coord_cg = {it->x_coord, it->y_coord, it->z_coord};
        }
    }

    std::vector<float> vector_a, vector_g;
    CrossProductMethod lone_pairs(&coord_cg, &coord_sd, &coord_ce);
    lone_pairs.get_vector_a(&vector_a);
    lone_pairs.get_vector_g(&vector_g);
}

void get_lone_pairs(std::vector<preprocessed> *met_data) {
    // get unique residue positions
    std::set<int> residue_positions;
	for (std::vector<preprocessed>::iterator it = met_data->begin(); it != met_data->end(); ++it) {
	 	residue_positions.insert(it->residue_position);
    }

    for (std::set<int>::iterator it_res = residue_positions.begin(); it_res != residue_positions.end(); ++it_res) {
        // group data according to unique residues
        std::vector<preprocessed> group;
        for (std::vector<preprocessed>::iterator it = met_data->begin(); it != met_data->end(); ++it) {
            if(it->residue_position == *it_res) {
                group.push_back(*it);
            }
        }

        get_lone_pairs_from_group(&group);
    }
}

#endif