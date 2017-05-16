#include <iostream>
#include <cmath>

double f(double x)
{
  return exp(x) + x*x*x -5.0;
}

double fp(double x)
{
  return exp(x) + 3*x*x;
}


int main()
{
  double xi,xf;
  xi = 0.0;
  xf = 0.0;
  double eps = 1e-8;
 //for(int i=0;i<100;i++)
 do 
   { 
    xi = xf;
    xf = xi - f(xi)/fp(xi); 
    std::cout<<xf<<"\n";
  }while(fabs(xi-xf)>eps);

 std::cout<<"\nFinal:"<<xf<<"\n";
 return 0;
}
