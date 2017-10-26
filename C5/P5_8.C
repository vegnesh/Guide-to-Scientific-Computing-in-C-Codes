#include <cmath>
#include <cassert>
#include <iostream>
#include <cstdlib>
#include <ctime>

void DetMat(double** A,double *d, double n );

double Check3Det(double** A, double n);
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

int main(int argc, char** argv)
{
      
      int n = 3; 
      if (argc>1)
	n = atoi(argv[1]);
      srand(time(NULL));

      double** A = CreateArray(n,n);

      for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
	  A[i][j] = rand()%10 + 1;
	}
      for(int i=0;i<n;i++)
      {
	if (i==0)
	  std::cout<<"A:\n";
	for(int j = 0;j<n;j++)
	std::cout<<A[i][j]<<"\t";
	std::cout<<"\n";
      }
      double* p = new double;
      *p  =3;
      DetMat(A,p,n);
      std::cout<<*p<<"\t"<<Check3Det(A,n)<<"\n";
//      std::cout<<DetMat(A,n)<<"\t"<<Check3Det(A,n)<<"\n";

//      std::cout<<Check3Det(A,n)<<"\n";
      FreeMemory(A,n);
      delete p;
      return 0;
  
}             

double Check3Det(double** A, double n)
{
 
  double det = A[0][0]*A[1][1]*A[2][2] + A[1][0]*A[2][1]*A[0][2] + A[2][0]*A[0][1]*A[1][2]
	     - A[0][0]*A[2][1]*A[1][2] -A[2][0]*A[1][1]*A[0][2] -A[1][0]*A[0][1]*A[2][2] ;
  return det;

}

void DetMat(double** A,double *d, double n)
{
  if(n==2)
    *d =  A[0][0]*A[1][1] - A[1][0]*A[0][1];
  else
    {
      double **tempMat = CreateArray(n-1,n-1);
      double *d2 = new double;
      *d2 = 0.0;
      *d = 0.0;
      for(int i=0;i<n;i++)
      {
	for(int k=0;k<n-1;k++)
	  for(int j=0;j<n-1;j++)
	  {
	      if (j<i)
		tempMat[k][j] = A[k+1][j];
	      else
		tempMat[k][j] = A[k+1][j+1];
	  }
	
	DetMat(tempMat,d2,n-1);
	*d += A[0][i]*pow(-1,i)*(*d2);
      }
      FreeMemory(tempMat,n-1);	
      delete d2;

    }
}
