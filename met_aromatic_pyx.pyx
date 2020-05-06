from libcpp.string cimport string

cdef extern from "met_aromatic.h":
    int met_aromatic_cpp(string code, string chain, float cutoff_distance)

def met_aromatic(string code, string chain, float cutoff_distance):
    return met_aromatic_cpp(code, chain, cutoff_distance)
