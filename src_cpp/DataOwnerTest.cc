#include <iostream>
#include <cassert>
#include <chrono>
#include "DataOwner.h"

uint64_t GetTimeStamp() {  // 直接调用此函数就可以返回时间戳了
  return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

void TestDataOwner(){
  std::cout << "_________ TestDataOwner Start ___________ \n";
  DataOwner<int> dataOwner;
  std::string arr_a="arr_a";
  dataOwner.create_array(10,arr_a);
  std::cout << "_________ TestDataOwner Done ___________ \n";
}
int main() {
  TestDataOwner();
}