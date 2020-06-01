# MetAromaticCPP
A small C++/Cython experiment. I ported Python code from [MetAromatic](https://github.com/dsw7/MetAromatic) to C++ with hopes that I could:
- Compile the Met-aromatic source to a standalone binary and also;
- Compile the Met-aromatic source to a shared object library that is importable into Python 
This work was done pretty much only out of personal interest. I don't think any lab staff that are unfamiliar with programming would have any interest in working with Makefiles, etc. 

## Technical details
This project currently targets C++17.

## Compilation options
To compile Cythonized C++ code:
```
cd src && ./compile_cython.sh
```
To compile pure C++ code:
```
cd src && ./compile_cxx.sh
```

## To run unit tests on Cython wrapper
```
cd src && python -m pytest -vs .
```
