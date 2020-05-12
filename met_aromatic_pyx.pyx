# cython: c_string_type=unicode, c_string_encoding=utf8

from libcpp.string cimport string
from libcpp.vector cimport vector

cdef extern from "met_aromatic.h":
    cdef struct results_single_interaction:
        string aromatic_residue 
        int aromatic_residue_position 
        string methionine_residue 
        int methionine_residue_position 
        float norm
        float met_theta
        float met_phi

    cdef struct results_all_interactions:
        int exit_code
        string reason
        vector [results_single_interaction] all_interactions

    results_all_interactions met_aromatic_cpp(string code, string chain, float cutoff_distance, float cutoff_angle)

def met_aromatic(string code, string chain, float cutoff_distance, float cutoff_angle):
    return met_aromatic_cpp(code, chain, cutoff_distance, cutoff_angle)
