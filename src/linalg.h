#ifndef LINALG_H
#define LINALG_H
#include <cmath>

void norm_vector(std::vector<float> *input_vec, float *norm) {
    double squares = 0.0;
    for (std::vector<float>::iterator it = input_vec->begin(); it != input_vec->end(); ++it) {
        squares += pow(*it, 2);
    }
    *norm = pow(squares, 0.5);
}

#endif