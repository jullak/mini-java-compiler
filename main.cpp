#include <iostream>

#include "Driver.hh"

int main(int argc, char ** argv) {
  int result;
  Driver driver;

  for (int i = 1; i < argc; ++i) {
    if (argv[i] == "-p") {}
    else if (argv[i] == "-s") {}
    else if (!driver.parse(argv[i])) {
      std::cout << "OK?.." << std::endl;
    } else {
      result = 1;
    }
  }

  return result;
}
