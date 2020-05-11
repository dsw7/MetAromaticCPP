from libcpp.string cimport string

cdef extern from "met_aromatic.h":
    int met_aromatic_cpp(string code, string chain, float cutoff_distance, float cutoff_angle)

def met_aromatic(string code, string chain, float cutoff_distance, float cutoff_angle):
    return met_aromatic_cpp(code, chain, cutoff_distance, cutoff_angle)
