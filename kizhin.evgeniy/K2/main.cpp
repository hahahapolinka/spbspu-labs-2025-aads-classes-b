#include <iostream>
#include "forward-list.hpp"

int main()
{
  kizhin::FwdList* list = kizhin::initList(1, 11);
  std::size_t position = 0;
  std::size_t size = 0;
  while (std::cin >> position >> size) {
    insertDuplicates(list, position, size);
  }
  kizhin::outputList(std::cout, list) << '\n';
}

