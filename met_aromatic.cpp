#include "met_aromatic.h"

void auxiliary_function(int *input_val, int *output_val) {
	*output_val = *input_val * 5;
}

int met_aromatic_cpp(int input_val) {
	int output;
	auxiliary_function(&input_val, &output);
	return output;
}