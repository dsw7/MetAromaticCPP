cdef extern from "met_aromatic.h":
    int met_aromatic_cpp(int input_val)

def met_aromatic(int input_val):
    return met_aromatic_cpp(input_val)