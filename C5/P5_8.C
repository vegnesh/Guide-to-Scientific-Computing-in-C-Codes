#include <cmath>
#include <cassert>
#include <iostream>

double DetMat(double** A, double n );

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

   // double A[2][2] = {{2,-3},{5,2}};
    //  double B[3][2] = {{1,2},{2,3},{3,4}};
  
      double** A = CreateArray(2,2);
        double** B = CreateArray(3,2);
  
          A[0][0]=2;A[0][1] = 3;A[1][0]=5;A[1][1] = 2;
            B[0][0]=1;B[0][1] = 2;B[1][0]=2;B[1][1] = 3;B[2][0]=3;B[2][1]=4;
 
      double** C = B+1; 
      std::cout<<C[0][0]<<C[0][1]<<C[1][0]<<C[1][1];
    //          Multiply(B,3,2,A,2,2);
                FreeMemory(A,2);
                  FreeMemory(B,3);
                    return 0;
  
}              
