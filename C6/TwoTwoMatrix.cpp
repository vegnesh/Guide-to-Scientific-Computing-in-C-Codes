#include "TwoTwoMatrix.hpp"
#include <cmath>

TwotwoMatrix::TwotwoMatrix()
{
  for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
      values[i][j]=0.0;
}

TwotwoMatrix::TwotwoMatrix(const TwotwoMatrix& z)
{
  for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
      values[i][j] = z.values[i][j];
}

TwotwoMatrix::TwotwoMatrix(double a, double b,double c, double d)
{
  values[0][0] = a;
  values[0][1] = b;
  values[1][0] = c;
  values[1][1] = d;
}

double TwotwoMatrix::Determinant()
{
  return values[0][0]*values[1][1] - values[0][1]*values[1][0];
}

TwotwoMatrix TwotwoMatrix::Inverse()
{
  TwotwoMatrix Temp;
  //Temp = *this;
  double detval = Determinant();
  if (Determinant()!=0)
  {
    Temp.values[0][0] = values[1][1]/detval;
    Temp.values[0][1] = -values[0][1]/detval;
    Temp.values[1][0] = -values[1][0]/detval;
    Temp.values[1][1] = values[0][0]/detval;


  }
  return Temp;
}

TwotwoMatrix& TwotwoMatrix::operator=(const TwotwoMatrix& z)
{
    values[0][0] = z.values[0][0];
    values[0][1] = z.values[0][1];
    values[1][0] = z.values[1][0];
    values[1][1] = z.values[1][1];

    return *this;
}

void TwotwoMatrix::ScalarMultiply(double x)
{
  for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
    {
      values[i][j] = x*values[i][j];
    }
}

TwotwoMatrix TwotwoMatrix::operator-() const
{
  TwotwoMatrix temp;
  for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
      temp.values[i][j] = -values[i][j];
  return temp;
}

TwotwoMatrix TwotwoMatrix::operator-(const TwotwoMatrix& z) const
{
  TwotwoMatrix temp;
  for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
      temp.values[i][j] = values[i][j] - z.values[i][j];
  return temp;

}

TwotwoMatrix TwotwoMatrix::operator+(const TwotwoMatrix& z) const
{ TwotwoMatrix temp;
  for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
      temp.values[i][j] = values[i][j] + z.values[i][j];
  return temp;

}

