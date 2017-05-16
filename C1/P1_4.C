#include <iostream>
#include <cmath>

int main(int argc, char** argv)
{
  double A[2][2] = {{1.1,2.2},{3.3,4.1}};
  double B[2][2] = {{-1. ,-1.},{-2.,-1.}};
  double C[2][2],D[2][2];

  for(int i = 0; i<2; i++)
    for(int j=0; j<2; j++)
      C[i][j] = A[i][j] + B[i][j];

  D[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0];
  D[0][1] = A[0][0]*B[0][1] + A[0][1]*B[1][1];
  D[1][0] = A[1][0]*B[0][0] + A[1][1]*B[1][0];
  D[1][1] = A[1][0]*B[0][1] + A[1][1]*B[1][1];

  std::cout<<"Matrix C:\n\t"<<C[0][0]<<" "<<C[0][1]<<"\n\t"<<C[1][0]<<" "<<C[1][1];
  std::cout<<"\nMatrix D:\n\t"<<D[0][0]<<" "<<D[0][1]<<"\n\t"<<D[1][0]<<" "<<D[1][1]<<"\n";
  
 return 0;
 
 
}

