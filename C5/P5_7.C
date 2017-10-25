#include <cmath>
// Function to calculate the p-norm of a vector:
// //
// = [ Sum_i ( |x_i|**p ) ] ** (1/p)
// // See "An Introduction to Numerical Analysis" by
// // Endre Suli and David Mayers, page 60, for definition


double CalculateNorm(double * x, int vecSize, int p = 2)
{
  double sum = 0.0;
  //Loop over elems x_i of x, incrementing sum by |x_i|**p
  for (int i=0; i<vecSize; i++)
  {
    double temp = fabs(x[i]);
    sum += pow(temp, p);
  }
  ////Return p-th root of sum

  return pow(sum, 1.0/p);
}

int main()
{
  return 0;
}
