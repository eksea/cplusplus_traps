#include <iostream>
#include <vector>

template <typename T>
class Foo
{
public:
  static std::vector<int> sv;
};

template <typename T>
std::vector<int> Foo<T>::sv;

class Bar
{};

class Bar2
{};

int main()
{
  Foo<Bar> f1;
  Foo<Bar2> f2;
  f1.sv.push_back(1);
  f2.sv.push_back(2);
  f2.sv.push_back(3);
  std::cout << "size of sv: " << f1.sv.size() << std::endl;
  return 0;
}

/*
 * 每个模板实例拥有独立的静态成员（非常好理解，本来每个模板实例都是一个独立的类）
 * 然而。。。。。。
 * 但是。。。。。。
 * 代码一长，特别是如果没有注意f1，f2的定义，很容易犯错，想当然地以为sv的size为3
*/
