rm -rf build/ *dll *so __pycache__/ met_aromatic_pyx.cpp 
python3 setup.py build_ext --inplace && python3 test.py
