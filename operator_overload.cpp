#include <iostream>
#include <boost/variant.hpp>

namespace cppt
{

struct Foo
{
};

}

std::ostream& operator<<(std::ostream& os, const cppt::Foo &foo)
{
  os << "a foo object" << std::endl;
  return os;
}

int main()
{
  boost::variant<cppt::Foo, std::string> v;
  std::cout << v;
  return 0;
}


/*
 * boost::variant只会在类型定义所在的命名空间内查找该类型的运算符重载函数
 * 一旦类型定义在某子命名空间，即使运算符重载出现在全局空间，程序依然无法编译成功
*/
