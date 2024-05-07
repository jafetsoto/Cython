// --------------------------------------------------------
// ------------------------Headers:------------------------ 
//#include <Python.h>
#include "CYTHON_CODE.h"                            // Generado por Cython.
#include <stdio.h>
#include <string.h>

// --------------------------------------------------------
// Prototipo de la función externa
void solicitar_datos(char *name, int *a, int *b);

// --------------------------------------------------------
int main() {
    Py_Initialize();

    // Añadir el directorio actual al sys.path para asegurarse de que el módulo pueda ser encontrado
    // PyObject *sysPath = PySys_GetObject("path");
    // PyObject *path = PyUnicode_FromString(".");
    // PyList_Append(sysPath, path);
    // Py_DECREF(path);

    // Solicitar datos al usuario
    char name[100];
    int a, b;
    solicitar_datos(name, &a, &b);

    // Cargar el módulo Cython
    PyObject *pName = PyUnicode_FromString("CYTHON_CODE");
    PyObject *pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        PyObject *pFunc = PyObject_GetAttrString(pModule, "cython_module");
        if (pFunc && PyCallable_Check(pFunc)) {
            // Crear una tupla para los argumentos de la función
            PyObject *pArgs = PyTuple_New(3);
            PyTuple_SetItem(pArgs, 0, PyUnicode_FromString(name));
            PyTuple_SetItem(pArgs, 1, PyLong_FromLong(a));
            PyTuple_SetItem(pArgs, 2, PyLong_FromLong(b));

            // Llamar a la función Cython con los argumentos
            PyObject *pResult = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);

            if (pResult != NULL) {
                printf("La función se ejecutó correctamente.\n");
                Py_DECREF(pResult);
            } else {
                PyErr_Print();
            }
            Py_DECREF(pFunc);
            
        } else {
            if (PyErr_Occurred()) PyErr_Print();
        }
        Py_DECREF(pModule);
    } else {
        PyErr_Print();
    }

    Py_Finalize();
    return 0;
}

// --------------------------------------------------------
// Declaración de la función para solicitar datos
void solicitar_datos(char *name, int *a, int *b) {
    printf("Ingrese su nombre: ");
    fgets(name, 100, stdin);                        // Leer una línea de texto incluyendo espacios
    name[strcspn(name, "\n")] = 0;                  // Eliminar el salto de línea

    printf("Ingrese el primer número: ");
    scanf("%d", a);
    printf("Ingrese el segundo número: ");
    scanf("%d", b);

    // Limpiar el buffer de entrada (en caso de que queden caracteres extra)
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}
// --------------------------------------------------------