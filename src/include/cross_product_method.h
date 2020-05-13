#ifndef CROSS_PRODUCT_METHOD_H
#define CROSS_PRODUCT_METHOD_H
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

#endif