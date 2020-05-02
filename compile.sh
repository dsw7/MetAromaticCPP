rm -rf build/ *dll *so __pycache__/ 
python3 setup.py build_ext --inplace && python3 test.py
