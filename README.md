# MetAromaticCPP
A Python wrapper over a C++ port of [MetAromatic](https://github.com/dsw7/MetAromatic). I chose to port to C++ for increased performance.  
Project is in its very early stages - check back soon.

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
