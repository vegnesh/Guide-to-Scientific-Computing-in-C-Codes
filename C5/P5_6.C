#include <iostream>
#include <cassert>

void Multiply(double** B,int ,int, double** A, int, int);

double** CreateArray(int row,int col)
{
  double** Array = new double*[row];
  for(int i=0;i<row;i++)
    Array[i] = new double [col];
  return Array;
}

void FreeMemory(double** A,int row)
{
  for(int i=0;i<row;i++)
    delete [] A[i];
  delete [] A;
}

int main()
{
 
//  double A[2][2] = {{2,-3},{5,2}};
//  double B[3][2] = {{1,2},{2,3},{3,4}};
    
  double** A = CreateArray(2,2);
  double** B = CreateArray(3,2);

  A[0][0]=2;A[0][1] = 3;A[1][0]=5;A[1][1] = 2;
  B[0][0]=1;B[0][1] = 2;B[1][0]=2;B[1][1] = 3;B[2][0]=3;B[2][1]=4;

  Multiply(B,3,2,A,2,2);
  FreeMemory(A,2);
  FreeMemory(B,3);
  return 0;

}

void Multiply(double** A,int r1,int c1,double** B,int r2,int c2)
{
  assert(c1 == r2);
  double temp =0;
  for (int i=0;i<r1;i++)
  {
    for(int j=0;j<c2;j++)
    {
      temp = 0;
      for(int k=0;k<c1;k++)
	temp += A[i][k]*B[k][j];

      std::cout<<temp<<" ";
    }
    std::cout<<"\n";
  }
}
