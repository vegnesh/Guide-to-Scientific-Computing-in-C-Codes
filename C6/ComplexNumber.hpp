#ifndef COMPLEXNUMBERHEADERDEF
#define COMPLEXNUMBERHEADERDEF

#include <iostream>

class ComplexNumber
{
private:
   double mRealPart;
   double mImaginaryPart;
public:
   ComplexNumber();
   ComplexNumber(double x, double y);
   double CalculateModulus() const;
   double CalculateArgument() const;
   ComplexNumber CalculatePower(double n) const;
   ComplexNumber& operator=(const ComplexNumber& z);
   ComplexNumber operator-() const;
   ComplexNumber operator+(const ComplexNumber& z) const;
   ComplexNumber operator-(const ComplexNumber& z) const;
   friend std::ostream& operator<<(std::ostream& output, 
                                   const ComplexNumber& z);
   friend double ImaginaryPart(const ComplexNumber& Z);
   friend double RealPart(const ComplexNumber& Z);
   double GetRealPart() const;
   double GetImaginaryPart() const;
   ComplexNumber(const ComplexNumber& z); 
   ComplexNumber(double x);
   ComplexNumber CalculateConjugate();
   void SetConjugate();
   ComplexNumber operator*(const ComplexNumber& z) const;
};

#endif
//Code from Chapter06.tex line 746 save as ComplexNumber.hpp
