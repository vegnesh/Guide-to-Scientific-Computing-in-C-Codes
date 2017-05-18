#include <iostream>
#include <cassert>

int main()
{
  for(int kj = 0;kj<100000000;kj++){
  int rows = 2; 
  int columns = 2;
  double** p_A = new double* [rows];
  double** p_B = new double* [rows];
  double** p_C = new double* [rows];

  assert(p_A != NULL);
  assert(p_B != NULL);
  assert(p_C != NULL);
  
  for(int i=0;i<rows;i++)
  {
    p_A[i] = new double[columns];
    p_B[i] = new double[columns];
    p_C[i] = new double[columns];

  } 

  for(int i=0;i<rows;i++)
    for(int j=0;j<columns;j++)
    {
      p_A[i][j] = i*j;
      p_B[i][j] = (i-1)*(j+2);
      p_C[i][j] = p_A[i][j] + p_B[i][j];

    }

  for(int i=0;i<rows;i++)
  {
    delete [] p_A[i];
    delete [] p_B[i];
    delete [] p_C[i];
  }


  delete [] p_A;
  delete [] p_B;
  delete [] p_C;
  }
  return 0;

}
