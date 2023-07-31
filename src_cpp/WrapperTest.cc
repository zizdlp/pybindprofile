#include <iostream>
#include <cassert>
#include <chrono>

#include "Operation.h"
#include "DataOwner.h"

uint64_t GetTimeStamp() {  // 直接调用此函数就可以返回时间戳了
  return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch())
      .count();
}

void TestWrapper(){
  std::cout << "_________  TestWrapper start ___________ \n";
  DataOwner<int> dataOwner;
  std::string arr_left="arr_left";
  std::string arr_right="arr_right";
  std::string arr_res="arr_res";
  int length=100000000;
  dataOwner.create_array(length,arr_left);
  dataOwner.create_array(length,arr_right);
  dataOwner.create_array(length,arr_res);

  auto left =dataOwner.get_array(arr_left);
  auto right =dataOwner.get_array(arr_right);
  auto res =dataOwner.get_array(arr_res);
  left->set_value(3);
  right->set_value(4);
  res->set_value(5);
  auto start_time=GetTimeStamp();
  mul(left,right,res);
  auto end_time=GetTimeStamp();
  // res->print_value();
  std::cout<<"Wrapper Test with length:"<<length<<"mul time consume:"<<end_time-start_time<<"ms"<<std::endl;
  std::cout << "_________  TestWrapper passed ___________ \n";
}
int main() {
  TestWrapper();
}