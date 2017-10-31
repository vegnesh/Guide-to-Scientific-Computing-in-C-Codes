#include <iostream>


class ConstTest
{
 
  int x;
  public:
  ConstTest(int a);
  void setx(int a);
  int  getx();

};

ConstTest::ConstTest(int a)
{
  x = a;

}

void ConstTest::setx(int a)
{
  x = a;
}

int ConstTest::getx()
{
  return x;

}

int main()
{
  ConstTest first(2);
  ConstTest* ptr  = new ConstTest(3);
  delete ptr;
  return 0;
}
