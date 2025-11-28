#include <Python.h>
#include <stdlib.h>

static int* arr = NULL;
static int arr_size = 0;

static PyObject* init(PyObject* self, PyObject* args) {
    int size;
    if (!PyArg_ParseTuple(args, "i", &size)) return NULL;
    arr = malloc(size * sizeof(int));
    arr_size = size;
    for (int i = 0; i < size; i++) arr[i] = 0;
    Py_RETURN_NONE;
}

static PyObject* set_val(PyObject* self, PyObject* args) {
    int idx, val;
    if (!PyArg_ParseTuple(args, "ii", &idx, &val)) return NULL;
    if (idx < 0 || idx >= arr_size) return PyErr_Format(PyExc_IndexError, "index out of range");
    arr[idx] = val;
    Py_RETURN_NONE;
}

static PyObject* get_val(PyObject* self, PyObject* args) {
    int idx;
    if (!PyArg_ParseTuple(args, "i", &idx)) return NULL;
    if (idx < 0 || idx >= arr_size) return PyErr_Format(PyExc_IndexError, "index out of range");
    return PyLong_FromLong(arr[idx]);
}

static PyObject* free_arr(PyObject* self, PyObject* args) {
    free(arr);
    arr = NULL;
    arr_size = 0;
    Py_RETURN_NONE;
}

static PyMethodDef Methods[] = {
    {"init", init, METH_VARARGS, "Initialize array"},
    {"set", set_val, METH_VARARGS, "Set value"},
    {"get", get_val, METH_VARARGS, "Get value"},
    {"free", free_arr, METH_NOARGS, "Free array"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef arraymodule = {
    PyModuleDef_HEAD_INIT,
    "array_module",
    NULL, -1, Methods
};

PyMODINIT_FUNC PyInit_array_module(void) {
    return PyModule_Create(&arraymodule);
}
