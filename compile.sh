rm -rf build/ *dll *so from_cython_to_python.cpp __pycache__/ 
python3 setup.py build_ext --inplace && python3 test.py
