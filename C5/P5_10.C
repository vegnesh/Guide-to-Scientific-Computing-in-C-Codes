#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

//*****************************************************************************//
//
//
//		This code performs Gaussian Elimination with Pivoting
//	  
//*****************************************************************************//
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

void FillArray(double **A,int row, int col)
{
  srand(time(NULL));
  
  for(int i=0;i<row;i++)
  {
    
    
    for(int j=0;j<col;j++)
      A[i][j] = (rand()%10)+1;
  }
 
}

void PrintArray(double** A, int row, int col)
{
  for(int i=0;i<row;i++)
  { 
    for(int j =0;j<col;j++)
      std::cout<<A[i][j]<<"\t";
    std::cout<<"\n";
  }
}

void CopyArray(double** A, double** B, int row, int col);

void SolveLinearSystem(double ** A, double ** x, double ** b, int n);


int main(int argc,char** argv)
{

  int n=3;
  if (argc>1)
    n = atoi(argv[1]);

  double** A = CreateArray(n,n);
  double** b = CreateArray(n,1);
  double** x = CreateArray(n,1);

  FillArray(A,n,n);
  FillArray(b,n,1);

  SolveLinearSystem(A,x,b,n);

  std::cout<<"A:\n";
  PrintArray(A,n,n);
  std::cout<<"x:\n";
  PrintArray(x,n,1);
  std::cout<<"b:\n";
  PrintArray(b,n,1);
  FreeMemory(A,n);
  FreeMemory(b,n);
  FreeMemory(x,n);
  
  return 0;
}

void CopyArray(double** A, double** B, int row, int col)
{
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
    {
      A[i][j] = B[i][j];
    }
}

void CheckMaxRowandSwap(double ** A, double** b, int n, int currRow)
{
  double max = fabs(A[currRow][currRow]);
  int swaprow = currRow;
  for(int i=currRow;i<n;i++)
  {
    if(max<fabs(A[i][currRow]))
  {
    max = fabs(A[i][currRow]);
    swaprow = i;
  }
  }

  if(swaprow != currRow)
  {
    double temp;
    for(int i=currRow;i<n;i++)
    {
      temp = A[currRow][i];
      A[currRow][i] = A[swaprow][i];
      A[swaprow][i] = temp;
      temp = b[currRow][0];
      b[currRow][0] = b[swaprow][0];
      b[swaprow][0] = temp;  
    }
  }


}

void SubtractStep(double ** A, double** b, int n, int currRow)
{
  for(int i=currRow+1; i<n;i++)
  {
    double mval = -A[i][currRow]/A[currRow][currRow];
    for(int j=currRow;j<n;j++)
    {
      A[i][j] = A[i][j] + mval*A[currRow][j];
    }
    b[i][0] = b[i][0] + mval*b[currRow][0];
  }
}


void SolveLinearSystem(double ** A, double ** x, double ** b, int n)
{
   double** tempMat1 = CreateArray(n,n);
   //double** tempMat2 = CreateArray(n,n);
   double** bvec1    = CreateArray(n,1);

   CopyArray(tempMat1,A,n,n);
   CopyArray(bvec1,b,n,1);

  for(int i=0;i<n-1;i++)
   {
//   std::cout<<"A:\n";  
//   PrintArray(tempMat1,n,n);
 
     CheckMaxRowandSwap(tempMat1,bvec1,n,i);
     SubtractStep(tempMat1,bvec1,n,i);
   }

  
  /*	  Solve Phase	      */

  PrintArray(tempMat1,n,n);
  PrintArray(bvec1,n,1);
  x[n-1][0] = bvec1[n-1][0]/tempMat1[n-1][n-1]; 
  for(int i=n-2;i>=0;i--)
  {
    double rhs = bvec1[i][0];
    for(int j=n-1;j>i;j--)
     rhs = rhs-tempMat1[i][j]*x[j][0];
    x[i][0] = rhs/tempMat1[i][i];
  }  
  
}

