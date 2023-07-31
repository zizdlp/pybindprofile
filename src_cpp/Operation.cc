#include "Operation.h"
#include "NumberArr.h"

template <typename T>
void mul(NumberArr<T>* left, NumberArr<T>* right, NumberArr<T>* res) {
    auto length = res->get_length();
    auto left_value = left->get_x();
    auto right_value = right->get_x();
    auto res_value = res->get_x();
    for (auto index = 0; index < length; ++index) {
        res_value[index] = left_value[index] * right_value[index];
    }
}

template void mul<int>(NumberArr<int>* left, NumberArr<int>* right, NumberArr<int>* res); //明显实例化函数模版
