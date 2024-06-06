
#include "ThirdPartyLib.h"
#include <iostream>

int foo(int arg) {
  std::cout << "Third party library :: foo called with " << arg << '\n';
  return 7;
}
