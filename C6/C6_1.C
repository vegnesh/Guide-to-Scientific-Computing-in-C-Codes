#include <iostream>
#include "ComplexNumber.hpp"

void TestComplex(ComplexNumber z);

ComplexNumber** CreateMatrix();
void DeleteMatrix(ComplexNumber** Matrix);
void MultiplyMatrix(ComplexNumber** A, ComplexNumber** B, ComplexNumber** Result);
void CalculateExponent(ComplexNumber** A, ComplexNumber** Result);
void EquateMatrix(ComplexNumber** A, ComplexNumber** B);
int main()
{

  ComplexNumber Z;
  ComplexNumber Z2(3,-2);
  Z2.SetConjugate();
  ComplexNumber Z3 = Z2.CalculateConjugate();
  std::cout<<"\n"<<Z2.GetRealPart()<<"\t"<<ImaginaryPart(Z2)<<"\n";
  std::cout<<"\n"<<Z3.GetImaginaryPart()<<"\t"<<RealPart(Z3)<<"\n";
  TestComplex(Z2);

  ComplexNumber** Temp = CreateMatrix();
  DeleteMatrix(Temp);
  return 0;

}

ComplexNumber** CreateMatrix()
{
  ComplexNumber** Matrix = new ComplexNumber*[3];
  for(int i=0;i<3;i++)
    Matrix[i] = new ComplexNumber[3];
  return Matrix;
}

void DeleteMatrix(ComplexNumber** Matrix)
{
  for(int i=0;i<3;i++)
    delete[] Matrix[i];
  delete[] Matrix;
}

void MultiplyMatrix(ComplexNumber** A, ComplexNumber** B, ComplexNumber** Result)
{
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      Result[i][j] = A[i][0]*B[0][j] + A[i][1]*B[1][j] + A[i][2]*B[2][j];
}

void EquateMatrix(ComplexNumber** A, ComplexNumber** B)
{
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    {
      A[i][j] = B[i][j];
    }
}

void EquateMatrixPlus(ComplexNumber** A, ComplexNumber** B, int n)
{
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    {
      A[i][j] = A[i][j] + B[i][j]*(1/n);
    }
}


void CalculateExponent(ComplexNumber** A, ComplexNumber** Result)
{
  
  ComplexNumber** temp = CreateMatrix();
  ComplexNumber** temp2 = CreateMatrix();

  EquateMatrix(temp,A);
  for(int i=0;i<10000;i++)
  {
    MultiplyMatrix(temp,A, temp2);
    EquateMatrixPlus(Result, temp2,i);
  }

  DeleteMatrix(temp);
  DeleteMatrix(temp2);
  
}

void TestComplex(ComplexNumber z)
{
  
}
