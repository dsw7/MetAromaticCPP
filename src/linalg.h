#ifndef LINALG_H
#define LINALG_H
#include <cmath>
#include <vector>

#define PI 3.14159265359

namespace linalg {
	void vector_scale(std::vector<float> *vec_a, float scalar, std::vector<float> *scaled) {
	    for (std::vector<float>::iterator it = vec_a->begin(); it != vec_a->end(); ++it) {
	    	scaled->push_back(*it * scalar);
	    }
	}

	void vector_add(std::vector<float> *vec_a, std::vector<float> *vec_b, std::vector<float> *sum) {
		for (unsigned int i = 0; i < vec_a->size(); ++i) {
			sum->push_back(vec_a->at(i) + vec_b->at(i));
		}
	}

	void vector_subtract(std::vector<float> *vec_a, std::vector<float> *vec_b, std::vector<float> *diff) {
		for (unsigned int i = 0; i < vec_a->size(); ++i) {
			diff->push_back(vec_a->at(i) - vec_b->at(i));
		}
	}

	void vector_average(std::vector<float> *vec_a, std::vector<float> *vec_b, std::vector<float> *avg) {
		for (unsigned int i = 0; i < vec_a->size(); ++i) {
			avg->push_back(0.5 * (vec_a->at(i) + vec_b->at(i)));
		}
	}

	void vector_norm(std::vector<float> *input_vec, float *norm) {
	    float squares = 0.0;
	    for (std::vector<float>::iterator it = input_vec->begin(); it != input_vec->end(); ++it) {
	        squares += pow(*it, 2);
	    }
	    *norm = pow(squares, 0.5);
	}

	void vector_unit(std::vector<float> *input_vec, std::vector<float> *unit_vec) {
		float squares = 0.0;	
		for (std::vector<float>::iterator it = input_vec->begin(); it != input_vec->end(); ++it) {
			squares += pow(*it, 2);
		}
		float norm = pow(squares, 0.5);
		vector_scale(input_vec, 1 / norm, unit_vec);
	}

	void vector_cross_product(std::vector<float> *vec_a, std::vector<float> *vec_b, std::vector<float> *cross) {
		*cross = {
			     ((vec_a->at(1) * vec_b->at(2)) - (vec_a->at(2) * vec_b->at(1))),
			-1 * ((vec_a->at(0) * vec_b->at(2)) - (vec_a->at(2) * vec_b->at(0))),
			     ((vec_a->at(0) * vec_b->at(1)) - (vec_a->at(1) * vec_b->at(0)))
		};
	}

	// returning a bool here might be a bit of over-engineering... at least in this program
	bool vector_dot_product(std::vector<float> *input_a, std::vector<float> *input_b, float *dot_product) {
	    unsigned int size_a = input_a->size();
	    unsigned int size_b = input_b->size();

	    if (size_a != size_b) {
	        return false;
	    }

	    float retval = 0.0;
	    for (unsigned int i = 0; i < size_a; ++i) {
	        retval += input_a->at(i) * input_b->at(i);
	    }

	    *dot_product = retval;
	    return true;
	}

	float radians_to_degrees(float radian) {
		return (180.00 / PI) * radian;
	}

	// returning a bool here might be a bit of over-engineering... at least in this program
	bool vector_angle(std::vector<float> *input_a, std::vector<float> *input_b, float *angle) {
	    unsigned int size_a = input_a->size();
	    unsigned int size_b = input_b->size();

	    if (size_a != size_b) {
	        return false;
	    }

	    float dot;
	    if (!vector_dot_product(input_a, input_b, &dot)) {
	        return false;
	    }

	    float norm_a, norm_b;
	    vector_norm(input_a, &norm_a);
	    vector_norm(input_b, &norm_b);

	    *angle = radians_to_degrees(acos(dot / (norm_a * norm_b)));
	    return true;
	}
}

#endif