#include <iostream>
#include "parse-args.hpp"

int main(int argc, char** argv)
{
  try {
    int result = kizhin::parseArgs(std::cerr, argc, argv);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
}

