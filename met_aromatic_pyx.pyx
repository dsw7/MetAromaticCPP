from libcpp.string cimport string

cdef extern from "met_aromatic.h":
    int met_aromatic_cpp(string code, string chain)

def met_aromatic(string code, string chain):
    return met_aromatic_cpp(code, chain)
