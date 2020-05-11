from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

CPP_COMPILE_V = '-std=c++17'
PATH_HEADER_FILES = ['src']
MACROS = [
	('DEBUG_BUILD', 1)  # 0 / 1 to compile debug build
]

EXTERNAL_MODULES = [
    Extension(
        "met_aromatic",
        ["met_aromatic_pyx.pyx", "met_aromatic.cpp"],
        language="c++",
        extra_link_args=["-lcurl"],  # add additional libs to link here
        include_dirs=PATH_HEADER_FILES,
        extra_compile_args=[CPP_COMPILE_V],
        define_macros=MACROS
    )
]

if __name__ == '__main__':
    setup(ext_modules=EXTERNAL_MODULES, cmdclass={'build_ext': build_ext})
