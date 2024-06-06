
#include <iostream>
#include <Windows.h>

int main(int argc, char** argv) {
  if(argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <path-to-our-dll>\n";
    return EXIT_FAILURE;
  }

  HINSTANCE dll = LoadLibrary(argv[1]);
  if(!dll) {
    std::cerr << "*** Error: Unable to load the library in '" << argv[1] << "'\n";
    return EXIT_FAILURE;
  }

  typedef int(*targetFunction)(int);

  targetFunction func = (targetFunction)(GetProcAddress(dll, "bar"));
  if(!func) {
    FreeLibrary(dll);
    std::cerr << "*** Error: Unable to find the function 'bar' within the library\n";
    return EXIT_FAILURE;
  }

  int result = func(42);
  std::cout << "Result of func(42): " << result << '\n';
  FreeLibrary(dll);
  return EXIT_SUCCESS;
}