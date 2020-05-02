# I'm not 100% if this is right...

cdef extern from "met_aromatic.h":
    int main_function(int input_val)

def main_function_py(int input_val):
    return main_function(input_val)
