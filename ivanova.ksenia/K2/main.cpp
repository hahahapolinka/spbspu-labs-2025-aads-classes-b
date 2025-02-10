#include <iostream>

struct FwdList {
  int value;
  FwdList* next;
};

FwdList* duplicate(FwdList* head, size_t index, size_t count)
{
  FwdList* current = head;

  for (size_t i = 0; i < index; i++)
  {
    current = current->next;
  }

  if (!current)
  {
    std::cerr << "Out of range" << '\n';
    return nullptr;
  }

  for (size_t i = 0; i < count; ++i) {
    FwdList* newNode = new FwdList{current->value, current->next};
    current->next = newNode;
    current = newNode;
  }
  return current;
}

int main() 
{

}
