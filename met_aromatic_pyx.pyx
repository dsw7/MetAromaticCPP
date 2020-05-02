from libcpp.string cimport string

cdef extern from "met_aromatic.h":
    int met_aromatic_cpp(string code)

def met_aromatic(string code):
    return met_aromatic_cpp(code)
