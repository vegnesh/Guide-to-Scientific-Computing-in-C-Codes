
#ifndef TWOTWOMATRIX
#include <iostream>

class TwotwoMatrix
{
  double values[2][2];
  public:
  TwotwoMatrix();
  TwotwoMatrix(const TwotwoMatrix& A);
  TwotwoMatrix(double a, double b, double c, double d);
  double Determinant();
  TwotwoMatrix Inverse();
  TwotwoMatrix& operator=(const TwotwoMatrix& z);
  void ScalarMultiply(double x);
  TwotwoMatrix operator-() const;
  TwotwoMatrix operator-(const TwotwoMatrix& z) const;
  TwotwoMatrix operator+(const TwotwoMatrix& z) const;
};
#define TWOTWOMATRIX

#endif
