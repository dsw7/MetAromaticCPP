#ifndef LINALG_H
#define LINALG_H
#include <cmath>
#include <vector>

void subtract_vector(std::vector<float> *vec_a, std::vector<float> *vec_b, std::vector<float> *diff) {
	for (unsigned int i = 0; i < vec_a->size(); ++i) {
		diff->push_back(vec_a->at(i) - vec_b->at(i));
	}
}

void norm_vector(std::vector<float> *input_vec, float *norm) {
    double squares = 0.0;
    for (std::vector<float>::iterator it = input_vec->begin(); it != input_vec->end(); ++it) {
        squares += pow(*it, 2);
    }
    *norm = pow(squares, 0.5);
}

#endif