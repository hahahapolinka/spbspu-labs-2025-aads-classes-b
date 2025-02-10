#include <iostream>
#include <cstddef>
#include "list.hpp"

namespace dribas
{
  FwdList* insert(FwdList* head, int index, size_t count) {
    if (index < 1) {
      throw std::out_of_range("index is out of range");
    }
    FwdList* current = head;
    for (int i = 1; i < index && current != nullptr; ++i) {
      current = current->next;
    }
    if (!current) {
      throw std::out_of_range("index is out of range");
    }
    for (size_t i = 0; i < count; i++) {
      FwdList* newNode = new FwdList{current->value, current->next};
      current->next = newNode;
      current = newNode;
    }

    return head;
}
  FwdList* makeList(FwdList* head, int size)
  {
    try {
      head = new FwdList {0, nullptr};
      FwdList* current = head;
      for (int i = 1; i < size; i++) {
        current->next = new FwdList {i, nullptr};
        current = current->next;
      }
    } catch (...) {
      throw;
    }
    return head;
  }
  void outList(std::ostream& out, FwdList* head)
  {
    if (head) {
      out << head->value;
      head = head->next;
      while (head) {
        out << " " << head->value;
        head = head->next;
      }
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
  constexpr int size = 10;

  dribas::FwdList * head = nullptr;
  try {
    head = makeList(head, size);
  } catch (const std::exception & e) {
    std::cerr << e.what() << '\n';
    clear(head);
    return 1;
  }

  dribas::FwdList* headPtr = head;

  while (std::cin) {
    int index = 0;
    size_t count = 0;
    if (std::cin >> index >> count) {
      try {
        head = insert(head, index, count);
      } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        clear(head);
        return 1;
      }
    }
  }

  outList(std::cout, headPtr);
  std::cout <<'\n';

  clear(headPtr);
  return 0;
}
