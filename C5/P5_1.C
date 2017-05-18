#include <iostream>
#include <cassert>

void Print(int* p_x);
int main()
{
  int x = 5;
  Print(&x);

  return 0;
}

void Print(int* p_a)
{
  std::cout<<"\nThe Number is:" << *p_a <<"\n";
}
