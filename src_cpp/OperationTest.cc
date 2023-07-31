#include <iostream>
#include <cassert>
#include <chrono>

#include "Operation.h"
#include "NumberArr.h"

uint64_t GetTimeStamp() {  // 直接调用此函数就可以返回时间戳了
  return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch())
      .count();
}

void TestOperation(){
  std::cout << "_________  TestOperation start ___________ \n";
  auto arr1 = new NumberArr<int>(5);
  auto arr2 = new NumberArr<int>(5);
  auto arr3 = new NumberArr<int>(5);
  arr1->set_value(3);
  arr2->set_value(5);
  arr3->set_value(5);
  mul(arr1,arr2,arr3);
  arr3->print_value();
  std::cout << "_________  TestOperation passed ___________ \n";
}
int main() {
  TestOperation();
}