#include "parse-args.hpp"
#include <iostream>

int kizhin::parseArgs(std::ostream& out, const int argc, const char* const* const argv)
{
  const char* appropriate_values[]{ "0", "1", "2" };
  if (argc != 2 || argv[1][0] == '\0' || argv[1][1] != '\0') {
    out << "Usage: " << argv[0] << " <0|1|2>\n";
  }
  /* TODO: validate values */
  return 0;
}

