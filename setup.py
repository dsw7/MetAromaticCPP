from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

EXTERNAL_MODULES = [
    Extension(
        "met_aromatic",
        ["met_aromatic_pyx.pyx", "met_aromatic.cpp"],
        language="c++",
        extra_link_args=["-lcurl"]  # add additional libs to link here
    )
]

if __name__ == '__main__':
    setup(ext_modules=EXTERNAL_MODULES, cmdclass={'build_ext': build_ext})
