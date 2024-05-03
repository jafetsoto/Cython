# =======================================================
# -------------------- setup.py --------------------------
# Este archivo sirve como un script de configuración para 
# construir el módulo Cython .c del archivo .pyx
# --------------------------------------------------------
from setuptools import setup
from Cython.Build import cythonize

setup(
    name = "CYTHON_PrintLib",
    ext_modules = cythonize("CYTHON_CODE.pyx", compiler_directives = {'language_level': "3"})
)
