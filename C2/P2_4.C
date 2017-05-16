#include <iostream>

void printvec(double x[3])
{
  for(int i=0;i<3;i++)
    std::cout<<"\n"<<x[i];
}
void printmat(double y[][3])
{
  for(int i=0;i<3;i++)
  { 
    for(int j=0;j<3;j++)
      std::cout<<y[i][j]<<" ";
    std::cout<<"\n";
  }
}

int main()
{
  double u[3] = {1.0, 2.0, 3.0};
  double v[3] = {6.0, 5.0, 4.0};
  double A[3][3] = {{1.0, 5.0, 0.0},
	          {7.0, 1.0, 2.0},
	          {0.0, 0.0, 1.0}};
  double B[3][3] = {{-2.0, 0.0, 1.0},
    {1.0, 0.0, 0.0},
    {4.0, 1.0, 0.0}};
  double w[3];
  for (int i=0; i<3; i++)
  {
    w[i] = u[i] - 3.0*v[i];
  }

  
  double x[3],y[3],z[3],C[3][3],D[3][3];

  for(int i=0;i<3;i++)
  {
    x[i] = u[i] - v[i];
    y[i] = A[i][0]*u[0] + A[i][1]*u[1] + A[i][2]*u[2];
    z[i] = y[i] - v[i];
    for(int j=0;j<=3;j++)
    {
      C[i][j] = 4*A[i][j] - 3*B[i][j];
      D[i][j] = A[i][0]*B[0][j] + A[i][1]*B[1][j] + A[i][2]*B[2][j];
    }
  }

  std::cout<<"\nx:";
  printvec(x);
  std::cout<<"\ny:";
  printvec(y);
  std::cout<<"\nz:";
  printvec(z);

  std::cout<<"\nC:";
  printmat(C);
  std::cout<<"\nD:";
  printmat(D);



   

  return 0;
}
