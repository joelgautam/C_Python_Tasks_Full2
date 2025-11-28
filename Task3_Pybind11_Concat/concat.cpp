#include <pybind11/pybind11.h>
#include <string>

namespace py = pybind11;

std::string concat(std::string a, std::string b) {
    return a + b;
}

PYBIND11_MODULE(concat_module, m) {
    m.def("concat", &concat, "Concatenate two strings");
}
