#include <iostream>
#include <cassert>
#include <cmath>

double meanfn(double A[], int n);
double stddev(double A[], int n);
int main()
{
  double x[5] = {5.3,-4.2,7.65,9.1,-24.23};
  std::cout<<"Mean:"<<meanfn(x,5)<<" Std Deviation:"<<stddev(x,5)<<"\n";
}

double meanfn(double A[], int n)
{
  double mean = 0.0;
  for(int i=0;i<n;i++)
    mean+= A[i];
  return mean/n;
}
double stddev(double A[], int n)
{
  double mean, std;
  std = 0.0;
  mean = meanfn(A,n);
  for(int i=0;i<n;i++)
  {
    std += pow(A[i] - mean,2);
  }
  std = sqrt(std/(n-1));
  return std;
}

