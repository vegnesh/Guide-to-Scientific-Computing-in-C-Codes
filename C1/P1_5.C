#include <iostream>
#include <cstring>


int main(int argc,char** argv)
{
  std::string fname;
  std::string lname;
  std::cout<<"\n Enter the first name: ";
  std::getline(std::cin,fname);
  std::cout<<"\n Enter the last name: ";
  std::getline(std::cin,lname);

  std::cout<<"\n The full name is :"<< fname <<" "<< lname<<std::endl;

  return 0;

}
