#include <iostream>
#include <cassert>

int  main()
{
  int x=4;
  int y=-5;

  int* p_x = &x ;
  int* p_y = &y ; 

  int* temp;

  temp = p_x;
  p_x = p_y;
  p_y = temp;

  std::cout<<*p_x<<" "<<*p_y<<"\n";
  return 0;
}
