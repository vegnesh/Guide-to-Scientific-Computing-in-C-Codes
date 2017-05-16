#include <iostream>
#include <cmath>
int main(int argc, char** argv)
{
  double A[3] = {1.2,2.5,-4.1},
	 B[3]={-0.4,6.2,5.1},
	 dotp=0.,
	 normA=0.,
	 normB=0.; 

  // dot product
  for(int i =0;i<3;i++)
  {
    dotp += A[i]*B[i];
    normA += A[i]*A[i];
    normB += B[i]*B[i];
  }
  
  normA = sqrt(normA);
  normB = sqrt(normB);

  std::cout<<"Dot Product: " <<dotp <<" NormA: "<<normA<<" NormB: "<<normB<<"\n";

  return 0;
}
