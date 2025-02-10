#include <iostream>

struct FwdList {
  int value;
  FwdList * next;
};

int main() 
{
  FwdList * head = new FwdList{0, nullptr};
  FwdList * tail = head;
  for (size_t i = 1; i < 10; i++)
  {
    tail->next = new FwdList{i, nullptr};
    tail = tail->next;
  }
  int a = 0, b = 0;
  while ( )
}
