#include <iostream>
#include <cassert>
int main()
{
  double A[2][2] = {{4,10},{1,1}};

  double invA[2][2];

  double det = 0;

  det = A[0][0]*A[1][1] - A[1][0]*A[0][1];
  assert(det !=0);
  
  invA[0][0] = A[1][1]/det;
  invA[1][1] = A[0][0]/det;
  invA[1][0] = -A[1][0]/det;
  invA[0][1] = -A[0][1]/det;
 
  std::cout<<"invA:\n"<<invA[0][0]<<" "<<invA[0][1]<<"\n"<<invA[1][0]<<" "<<invA[1][1]<<"\n";


}
