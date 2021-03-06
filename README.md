# MetAromaticCPP
A small C++/Cython experiment. I ported Python code from [MetAromatic](https://github.com/dsw7/MetAromatic) to C++ with hopes that I could:
- Compile the Met-aromatic source to a standalone binary and also;
- Compile the Met-aromatic source to a shared object library that is importable into Python 

This work was done pretty much only out of personal interest. I don't think any lab staff that are unfamiliar with programming would have any interest in working with Makefiles, etc. 

## Technical details
This project currently targets C++17.

## To compile (and play around with) Cythonized code:
```
cd src && ./compile_cython.sh
```
The `runner.py` file in the `src` directory is the "wrapper" that imports the shared object file that is generated by the `compile_cython.sh` script. To run the file:
```
./runner.py <pdb-code>
```

## To compile a binary directly from the C++ source:
```
cd src && ./compile_cxx.sh
```
The binary will be dumped into the `bin` directory. To actually run a Met-aromatic calculation using the binary: 
```
cd bin && ./met_aromatic.exe --ai <pdb-code>
```
The binary is very simple and takes no other parameters or flags. See the `CMakeLists.txt` file to specify cutoff conditions. The cutoff conditions can be set under the `# user defined macro definitions` section.

## To run unit tests on Cython wrapper
I added some unit tests for the shared object library. Here's how to run them:
```
cd src && ./compile_cython.sh && python -m pytest -vs .
```
