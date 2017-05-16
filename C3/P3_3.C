#include <iostream>
#include <cassert>
#include <fstream>
#include <cstdlib>
int main(int argc, char **argv)
{
  if(argc < 2)
  {
    std::cout<<"\nThe run time command should be of the form ./P3_3 100\n";
    return 1;
  }

  unsigned int Ng = 100;

  Ng = atoi(argv[1]);

  assert(Ng>1);

  double xmin = 0.0;
  double xmax = 1.0;

  double h = (xmax - xmin)/(Ng-1.0);

  double y0 = 1;
  double yp,yc;

  std::ofstream Output_file("xy.dat");
  assert(Output_file.is_open());

  Output_file<<"X\t" <<"Y";
  Output_file<<"\n"<<xmin<<"\t"<<y0;

  double xc = xmin;
  yp = y0;
  for(unsigned int i=0;i<Ng;i++)
  {
    xc = xc + h;
    yc = yp/(1.0+h);
    Output_file<<"\n"<<xc<<"\t"<<yc;
    yp = yc;
  }

  Output_file.close();


  return 0;

}
