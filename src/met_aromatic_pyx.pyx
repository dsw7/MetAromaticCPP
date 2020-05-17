# cython: c_string_type=unicode, c_string_encoding=utf8

from libcpp.string cimport string
from libcpp.vector cimport vector

cdef extern from "met_aromatic.h":
    cdef struct results_single_interaction:
        string aromatic_residue 
        int aromatic_position 
        int methionine_position 
        float norm
        float met_theta_angle
        float met_phi_angle

    cdef struct results_all_interactions:
        string _id
        int exit_code
        string exit_status
        vector [results_single_interaction] results

    results_all_interactions met_aromatic_cpp(string code, string chain, float cutoff_distance, float cutoff_angle)

def met_aromatic(code, chain, cutoff_distance, cutoff_angle):
    return met_aromatic_cpp(
        code.encode('utf-8'),
        chain.encode('utf-8'),
        cutoff_distance,
        cutoff_angle
    )
