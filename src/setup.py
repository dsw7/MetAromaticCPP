from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

CPP_VERSION = '-std=c++17'

PATH_HEADER_FILES = [
    'include'
]

MACROS = [
	('DEBUG_PHE', 0),   # midpoints, preprocessed aromatics
    ('DEBUG_TYR', 0),   # midpoints, preprocessed aromatics
    ('DEBUG_TRP', 0),   # midpoints, preprocessed aromatics
    ('DEBUG_MET', 0),   # lone pairs, preprocessed methionines
    ('DEBUG_CURL', 1),  # download    
]

LINK_LIBRARIES = [
    "-lcurl"
]

EXTRA_COMPILE_ARGS = [
    CPP_VERSION
]

EXTERNAL_MODULES = [
    Extension(
        "met_aromatic",
        ["met_aromatic_pyx.pyx", "met_aromatic.cpp"],
        language="c++",
        include_dirs=PATH_HEADER_FILES,
        define_macros=MACROS,
        extra_link_args=LINK_LIBRARIES,
        extra_compile_args=EXTRA_COMPILE_ARGS
    )
]

if __name__ == '__main__':
    setup(ext_modules=EXTERNAL_MODULES, cmdclass={'build_ext': build_ext})
