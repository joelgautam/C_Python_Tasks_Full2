#include <Python.h>

static PyObject* square(PyObject* self, PyObject* args) {
    int x;
    if (!PyArg_ParseTuple(args, "i", &x))
        return NULL;
    return PyLong_FromLong(x * x);
}

static PyMethodDef SquareMethods[] = {
    {"square", square, METH_VARARGS, "Return square"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef squaremodule = {
    PyModuleDef_HEAD_INIT,
    "square_module",
    "A module for squaring numbers",
    -1,
    SquareMethods
};

PyMODINIT_FUNC PyInit_square_module(void) {
    return PyModule_Create(&squaremodule);
}
