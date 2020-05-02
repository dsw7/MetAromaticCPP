from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

EXTERNAL_MODULES = [
	Extension(
		"main_function",
		["met_aromatic_pyx.pyx", "met_aromatic.cpp"],
		language="c++",
	)
]

setup(ext_modules=EXTERNAL_MODULES, cmdclass={'build_ext': build_ext})
