#include "NumberArr.h"

#include <vector>
#include <iostream>



template <typename T>
NumberArr<T>::NumberArr(int length) : x(new T[length]), length_(length) {
    std::cout << "create NumberArr object with length: " << length << std::endl;
}

template <typename T>
T* NumberArr<T>::get_x() const {
    return  x;
}

template <typename T>
void NumberArr<T>::print_value() {
    for (auto index = 0; index < length_; ++index) {
        std::cout << "value at key: " << index << " is: " << x[index] << std::endl;
    }
}

template <typename T>
void NumberArr<T>::set_value(int value) {
    for (auto index = 0; index < length_; ++index) {
        x[index]=value;
    }
}

template <typename T>
int NumberArr<T>::get_length() {
    return length_;
}



template class NumberArr<int>; //这个必须，编译需要知道哪些模版类型需要添加。