#include <pybind11/pybind11.h>
#include "src_cpp/Operation.h"
#include "src_cpp/NumberArr.h"
#include "src_cpp/DataOwner.h"

#include <iostream>
namespace py = pybind11;


struct DataWrapper {
  public:
    DataWrapper(){ std::cout<<"create Datawrapper";}
    void createData(int length,std::string name){
      dataOwner.create_array(length,name);
    }
    void setValue(int value,std::string name){
      auto left =dataOwner.get_array(name);
      left->set_value(value);
    }
    void mul_operation(std::string name_left,std::string name_right,std::string name_res){
      auto left =dataOwner.get_array(name_left);
      auto right =dataOwner.get_array(name_right);
      auto res =dataOwner.get_array(name_res);
      mul(left,right,res);
    }
    void print_value(std::string name){
      auto left =dataOwner.get_array(name);
      left->print_value();
    }
  private:
    DataOwner<int> dataOwner;
};


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
  // m.def("mul", &mul_c, "A  c function that mul two numbers");
  py::class_<UCharP>(m, "UCharP")
      .def(py::init<int>())
      .def("set", &UCharP::set)
      .def("Value", &UCharP::Value, "print the unsigned char array value Encapsulated by UCharP")
      .def("__repr__", [](const UCharP &self) { return "<UCharP obj which like an unsigned char array>"; });
  py::class_<DataWrapper>(m, "DataWrapper")
      .def(py::init())
      .def("setValue", &DataWrapper::setValue)
      .def("createData", &DataWrapper::createData, "create array")
      .def("mul_operation", &DataWrapper::mul_operation, "mul array")
      .def("print_value", &DataWrapper::print_value, "print array")
      .def("__repr__", [](const UCharP &self) { return "<UCharP obj which like an unsigned char array>"; });
}
