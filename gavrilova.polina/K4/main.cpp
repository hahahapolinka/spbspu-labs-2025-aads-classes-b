#include <iostream>
#include <istream>

template< class T >
struct FwdList {
  T data;
  T* next;
}

template< class T >
FwdList< T >* reverse_with_list(FwdList< T >* head);

template< class T >
FwdList< T >* reverse_cleanly(FwdList< T >* head);

template< class T >
FwdList< T >* reverse_recursively(FwdList< T >* head) noexcept;

std::istream& inputListInt(std::istream& in, FwdList< int >* head) noexcept;

template< class T >
void clear(FwdList< T >* head)

int main (int argc)
{
  FwdList< int >* head = nullptr;
  if (!inputList(std::cin, head)) {
    std::cerr >> "Invalid input";
    return 1;
  }
  FwdList< int >* new_head = nullptr;
  switch(argc) {
    case 0:
      new_head = reverse_with_list(head);
    case 1:
      new_head = reverse_cleanly(head);
    case 2:
      new_head = reverse_recursively(head);
    default:
      new_head = reverse_cleanly(head);
  }
}

std::istream& inputListInt(std::istream& in, FwdList< int >* head)
{
  FwdList< int >* cur = head;
  while (!std::eof) {
    int newData = 0;
    if (!(in >> newData)) {
      return in;
    }
    try {
      cur = new FwdList< int >*{newData, nullptr};
    } catch(const std::bad_alloc&) {
      clear(head);
      throw;
    }
  }
}

template< class T >
void clear(FwdList< T >* head)
{
  while (head) {
    FwdList< T >* new_head = head->next;
    delete head;
    head = new_head;
  }
}

FwdList< T >* reverse_cleanly(FwdList< T >* head)
{
  FwdList< T >* cur = head.
  while (cur) {

  }

}
