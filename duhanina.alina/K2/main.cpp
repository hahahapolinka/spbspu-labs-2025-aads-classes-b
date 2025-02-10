#include <iostream>
#include <stdexcept>

struct FwdList
{
  int value;
  FwdList* next;
};

FwdList* insertDuplicates(FwdList* head, size_t position, size_t count)
{
  FwdList* current = head;
  for (size_t i = 1; i <= position && current != nullptr; ++i)
  {
    current = current->next;
  }
  if (current == nullptr)
  {
    throw std::out_of_range("Position is out of range");
  }
  for (size_t i = 0; i < count; ++i)
  {
    FwdList* newNode = new FwdList{current->value, current->next};
    current->next = newNode;
    current = newNode;
  }
  return head;
}

int main()
{
  
}
