#include <iostream>
#include <cassert>

void ChangePrint(int* p_x);
int main()
{
  int x = 5;
  ChangePrint(&x);
  ChangePrint(&x);
  return 0;
}

void ChangePrint(int* p_a)
{
  std::cout<<"\nThe Number is:" << ++(*p_a) <<"\n";
}
