#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr pL;
  
  pL.push_front("8073");
  pL.push_back("765");
  pL.push_front("1024");
  pL.pop_back();
  pL.push_front("1536");
  pL.pop_front();
  int size = pL.size();
  for (int i=0;i<size;i++) {
    std::cout << pL.get(i) << std::endl;
  }
  // should print out 1024 then 8073
  
}
