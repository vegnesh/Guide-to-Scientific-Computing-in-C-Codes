#include <iostream>
#include <cassert>

int main()
{
  int i = 5;
  int* p_j = &i;

  *p_j = *p_j*5;

  int* p_k = new  int;
  *p_k = *p_j;

  std::cout<<*p_j<<" "<<*p_k<<" "<<p_j<<" "<<p_k<<"\n" ;
  delete p_k;
  return 0;

}
