#include <pybind11/pybind11.h>
#include "src_cpp/operation_cpp.h"
namespace py = pybind11;
struct UCharP {
  unsigned char *value;
  int size;
  UCharP(int size) : size(size) { value = new unsigned char[size]; }
  void set(std::string inputs) {
    for (int i = 0; i < inputs.size(); ++i) {
      value[i] = inputs[i];
    }
  }
  ~UCharP() { delete[] value; }
  py::bytes Value() {
    std::string output = "";
    for (int i = 0; i < size; ++i) {
      output.push_back(value[i]);
    }
    return py::bytes(output);
  }
};
PYBIND11_MODULE(pybindc, m) {
  m.def("mul", &mul_c, "A  c function that mul two numbers");
  py::class_<UCharP>(m, "UCharP")
      .def(py::init<int>())
      .def("set", &UCharP::set)
      .def("Value", &UCharP::Value, "print the unsigned char array value Encapsulated by UCharP")
      .def("__repr__", [](const UCharP &self) { return "<UCharP obj which like an unsigned char array>"; });
}
