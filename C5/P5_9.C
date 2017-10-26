#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime> 

void SolveLinearSystem(double ** A, double * x, double * b, int n);

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
  int n=3;
  double **A = CreateArray(n,n);

  double* x = new double[n];
  double* b = new double[n];


  srand(time(NULL));
  
  for(int i=0;i<n;i++)
  {
    b[i] = (rand()%10);
    
    for(int j=0;j<n;j++)
      A[i][j] = (rand()%10)+1;
  }
  
  SolveLinearSystem(A,x,b,n);


  for(int i=0;i<3;i++)
  {
    if (i==0)
    std::cout<<"A:\n";
    std::cout<<A[i][0]<<"\t"<<A[i][1]<<"\t"<<A[i][2]<<"\n";

    if(i==2)
    {  std::cout<<"B:\n";
       std::cout<<b[0]<<"\t"<<b[1]<<"\t"<<b[2]<<"\n";
       std::cout<<"X:\n";
       std::cout<<x[0]<<"\t"<<x[1]<<"\t"<<x[2]<<"\n";
    }
  }
  FreeMemory(A,n);
}

void SolveLinearSystem(double ** A, double * x, double * b, int n)
{ 

  
  double det = A[0][0]*A[1][1]*A[2][2] + A[1][0]*A[2][1]*A[0][2] + A[2][0]*A[0][1]*A[1][2]
	     - A[0][0]*A[2][1]*A[1][2] -A[2][0]*A[1][1]*A[0][2] -A[1][0]*A[0][1]*A[2][2] ;

  double ** temp = CreateArray(n,n);

  temp[0][0] =( A[1][1]*A[2][2] - A[1][2]*A[2][1])/det ;
  temp[0][1] =( A[0][2]*A[2][1] - A[0][1]*A[2][2])/det ;
  temp[0][2] =( A[0][1]*A[1][2] - A[0][2]*A[1][1])/det ;
  temp[1][0] =( A[1][2]*A[2][0] - A[1][0]*A[2][2])/det ;
  temp[1][1] =( A[0][0]*A[2][2] - A[0][2]*A[2][0])/det ;
  temp[1][2] =( A[0][2]*A[1][0] - A[0][0]*A[1][2])/det ;
  temp[2][0] =( A[1][0]*A[2][1] - A[1][1]*A[2][0])/det ;
  temp[2][1] =( A[0][1]*A[2][0] - A[0][0]*A[2][1])/det ;
  temp[2][2] =( A[0][0]*A[1][1] - A[0][1]*A[1][0])/det ;


  for(int i=0;i<3;i++)
  {
    x[i] = temp[i][0]*b[0] + temp[i][1]*b[1] + temp[i][2]*b[2];
  }
  FreeMemory(temp,n);


}

