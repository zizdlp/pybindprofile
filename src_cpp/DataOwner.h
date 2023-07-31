#ifndef DATAOWNER_H
#define DATAOWNER_H

#include "NumberArr.h"

#include <iostream>
#include <unordered_map>
#include <string>


template <typename T>
class DataOwner {
public:
    DataOwner(){
        std::cout<<"create DataOwner"<<std::endl;
    }
    void create_array(int length, std::string string_name);
    NumberArr<T>* get_array(std::string string_name); // 注意这里返回引用
private:
    std::unordered_map<std::string,NumberArr<T>*> arrs;
};


#endif // DATAOWNER_H
