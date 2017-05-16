#include <iostream>

int main(int argc, char** argv)
{
  int A[5] = {34,58,57,32,43};

  std::cout<<"\n Average: " << double(A[0]+A[1]+A[2]+A[3]+A[4])/5.0<<"\n";
  return 0;
}
