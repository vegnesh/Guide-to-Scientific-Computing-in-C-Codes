#include <iostream>

int main(int argc, char** argv)
{
  int a,b,c;

  std::cout<<"Enter first number:";
  std::cin>>a;
  std::cout<<"Enter the second number:";
  std::cin>>b;
  c = a*b;
  std::cout<<"The product of 2 nos is:" <<c <<"\n";
  // The following line flushes output before performing any computation
  std::cout.flush();
  return 0;

}
