#include <iostream>
#include <cstddef>
#include "list.hpp"

namespace dribas
{
  FwdList* insert(FwdList* head, int index, size_t count)
  {
    FwdList* interim = head;
    for (size_t i = 0; i < index && interim != nullptr; ++i) {
      interim = interim->next;
      if (!head) {
        throw std::out_of_range("index is out of range");
      }
    }
    FwdList* nextNode = nullptr;
    if (interim->next) {
      nextNode = interim->next;
    }
    for (size_t i = 0; i < count; i++) {
      FwdList* preNode = nullptr;
      try {
        preNode = new FwdList{index, nullptr};
      } catch (const std::bad_alloc&) {
        head->next = nextNode;
        throw;
      }
      preNode->next = interim->next;
      interim = preNode;
    }
  }

  FwdList* makeList(FwdList* head, size_t size)
  {
    try {
      head = new FwdList {0, nullptr};
      for (size_t i = 0; i < size; i++) {
        head->next = new FwdList {0, nullptr};
        head = head->next;
      }
    } catch (...) {
      throw;
    }
    return head;
  }
  void outList(std::ostream& out, FwdList* head)
  {
    out << head->value;
    head = head->next;
    while (head) {
      out << " " << head->value;
      head = head->next;
    }
  }
  void clear(FwdList* head)
  {
    FwdList* interim = head;
    while (head) {
      interim = head->next;
      delete head;
      head = interim;
    }
  }
}

int main()
{
  constexpr size_t  size = 10;

  dribas::FwdList * head = nullptr;
  try {
    head = dribas::makeList(head, size);
  } catch (const std::bad_alloc & e) {
    std::cerr << e.what() << '\n';
    clear(head);
    return 1;
  }
  while(!(std::cin.eof())) {
    size_t index = 0;
    size_t count = 0;
    if (std::cin >> index >> count) {
      
    }
  }
}
