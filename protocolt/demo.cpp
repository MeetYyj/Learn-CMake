
#include <iostream>
#include "pbb/news.pb.h"
#include <string>
using namespace std;
int main(){

  std::cout << "hello" << std::endl;
  test::Fuck msg1;
  msg1.set_mm(102);
  msg1.set_m_str("hehahah");
  std::cout << msg1.mm() << std::endl;
  std::cout << msg1.m_str() << std::endl;

  string str;
  msg1.SerializeToString(&str);
  std::cout << "str: " << str << std::endl;


  test::Fuck msg_rcv;
  msg_rcv.ParseFromString(str);

  cout << msg_rcv.mm() << " " << msg_rcv.m_str() << endl;


  return 0;


}
