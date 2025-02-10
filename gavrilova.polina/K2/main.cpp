#include <iostream>

struct FwdList {
  int value;
  FwdList * next;
};

dublicate(FwdList * head, size_t for_dubl, size_t number);
createList(FwdList * head, size_t size);
outList(FwdList * head);

int main()
{
  FwdList * head = nullptr;
  try {
    createList(head, 10)
  } catch(const std::bad_alloc &) {
    std::err << "Memory error!"
    return 1;
  }
  
  while (std::cin && std::cin.eof()) {
    size_t for_dubl = 0;
    size_t num = 0;
    std::cin >> for_dubl >> num;
    try {
      FwdList * node = dublicate(head, for_dubl, num);
    } catch(const std::bad_alloc&) {
      std::err << "Memory error!"
      return 1;
    }
  }
  outList(head);
}