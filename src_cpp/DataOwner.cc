#include "DataOwner.h"

#include <iostream>


template <typename T>
void DataOwner<T>::create_array(int length, std::string string_name) {
    std::cout<<"call create_array"<<std::endl;
    arrs[string_name] = new NumberArr<T>(length);
    std::cout << "Array created with name: " << string_name << std::endl;
}

template <typename T>
NumberArr<T>* DataOwner<T>::get_array(std::string string_name) {
    return arrs[string_name];
}


template class DataOwner<int>; //这个必须，编译需要知道哪些模版类型需要添加。