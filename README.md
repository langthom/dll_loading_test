# dll_loading_test
Small test repository to check the validity of loading dlls dynamically which themselves depend on a third party library, which might be build statically or dynamically.
To this this, please build this project and set the CMake variable BUILD_THIRD_PARTY_STATIC to either ON or OFF, depending on the test case.

## Motivation
Two combinations are essentially possible:
  1. The third party library is built statically.
  2. The third party library is built dynamically.

Either way, the calling library (labeled "our lib") is always built dynamically.
The third party library exports a function "foo" which is called by the function "bar" exported from our library.

The executable which is built here expects one command line argument specifying the path to our dll. It then tries to load the library dynamically and call the function "bar".
If this works, the following output is printed to the console window:
```
Third party library :: foo called with 42
Result of func(42): 7
```
Otherwise, according error messages are printed.

## Observations
We can make the following observations from different test cases.

Test 1: The third party library is built dynamically and both libraries are in the same directory as the executable.
- Works

Test 2: The third party library is built dynamically but the libraries are in a different directory than the executable.
- Does not work

Test 3: The third party library is built statically and both libraries (i.e., only "our" dll) are in the same directory as the executable.
- Works

Test 4: The third party library is built statically but the libraries (i.e., only "our" dll) are in a different directory than the executable.
- Works

