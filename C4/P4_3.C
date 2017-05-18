#include <iostream>
#include <cassert>

int main()
{
  
  for (int i = 0;i<1000000000;i++){
  double* p_x = new double[3];
  double* p_y = new double[3];
  assert(p_x != NULL);
  assert(p_y != NULL);
  
  p_x[0] = 2.4;p_x[1] = -1.7;p_x[2] = 5.123;
  p_y[0] = -1.4;p_y[1] = 3.7;p_y[2] = 1.321;


  double inner = 0;
  for(int k=0;k<3;k++)
    inner += p_x[k]*p_y[k];
  delete [] p_x;
  delete [] p_y;
  
  }
  
  return 0;

}
