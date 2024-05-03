# Importar la función Python
from Pure_Python import factorial_recursive

# CYTHON_CODE.pyx

cpdef public int cython_module(str name, int a, int b):
    print("Inicio del llamado a la función Cython.")
    print("Nombre:", name)

    # Llamada a la función Python desde Cython
    cdef int result_a = factorial_recursive(a)
    cdef int result_b = factorial_recursive(b)


    print(f"El factorial de {a} es {result_a}")
    print(f"El factorial de {b} es {result_b}")
    
    return a + b
    