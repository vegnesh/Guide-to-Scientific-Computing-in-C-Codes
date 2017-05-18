#include <iostream>
#include <cassert>

void swap_p(double *, double*);
void swap_r(double &, double&);

int main()
{
  double x=5, y=-7;
  swap_p(&x,&y);
  std::cout<<"x:"<<x<<" "<<"y:"<<y<<"\n";
  swap_r(x,y);
  std::cout<<"x:"<<x<<" "<<"y:"<<y<<"\n";
  return 0;

}

void swap_p(double* a,double* b)
{
  double temp = *a;
  *a = *b;
  *b = temp;
}

void swap_r(double &a,double& b)
{
 double temp = a;
 a = b;
 b = temp;
}
