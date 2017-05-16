#include <iostream>

int main()
{
  
  int x=0;
  int sum = 0;
  while(x != -1) 
  {
    if(x==-2)
    {
      sum=0;
      x = 0;
      continue;
    }  

    if(sum>100)
      break;  
    sum += x;   
    std::cout<<"\nEnter the Number:";
    std::cin>> x;

  }

  std::cout<<"\nThe sum is:"<<sum<<"\n";
  return 0;
}
