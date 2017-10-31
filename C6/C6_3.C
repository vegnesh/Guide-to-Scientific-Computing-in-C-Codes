#include <iostream>
#include "TwoTwoMatrix.hpp"


int main()
{
  TwotwoMatrix a;
  TwotwoMatrix *p = new TwotwoMatrix(1,2.3,1,-4.7);

  TwotwoMatrix q;
  q = *p;

  TwotwoMatrix r = -q;
  TwotwoMatrix z;
  z = q+r;
  z = r-z;
  z.ScalarMultiply(3.54);
  a = z.Inverse();

  delete p;
}
